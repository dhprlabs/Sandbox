#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "GLEW/GL/glew.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) 
        return -1;

    /* triangle co-ordinates */
    float vertices_1[] = {
       -0.5f,  0.0f,  0.0f,
       -0.25f, 0.0f,  0.0f,
       -0.37f, 0.25f, 0.0f
    };
	
	float vertices_2[] = {
	    0.25f, 0.0f,  0.0f,
		0.5f,  0.0f,  0.0f,
		0.37f, 0.25f, 0.0f
	};

	/* simple vertex shader code (GLSL) */
	const char* vertexShaderSource = "#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
	"}\0";

	/* generating vertex shader */
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	/* simple fragment shader code (GLSL) */
	const char* fragmentShaderSource_1 = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}\0";

	const char* fragmentShaderSource_2 = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"FragColor = vec4(0.5f, 0.5f, 0.2f, 1.0f);\n"
	"}\0";
	
	/* generating fragment shader */
	unsigned int fragmentShader_1;
	fragmentShader_1 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader_1, 1, &fragmentShaderSource_1, NULL);
	glCompileShader(fragmentShader_1);
	
	unsigned int fragmentShader_2;
	fragmentShader_2 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader_2, 1, &fragmentShaderSource_2, NULL);
	glCompileShader(fragmentShader_2);
	
	/* creating shader program & linking shaders */
	unsigned int shaderProgram[2];
	
	shaderProgram[0] = glCreateProgram();
	glAttachShader(shaderProgram[0], vertexShader);
	glAttachShader(shaderProgram[0], fragmentShader_1);
	glLinkProgram(shaderProgram[0]);
	
	shaderProgram[1] = glCreateProgram();
	glAttachShader(shaderProgram[1], vertexShader);
	glAttachShader(shaderProgram[1], fragmentShader_2);
	glLinkProgram(shaderProgram[1]);

	/* delete shader objects */
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader_1);
	glDeleteShader(fragmentShader_2);

	/* generating vertex buffer & array object */
	unsigned int VAO[2], VBO[2];
	glGenBuffers(2, VBO);
	glGenVertexArrays(2, VAO);

	glBindVertexArray(VAO[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_1), vertices_1, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	glBindVertexArray(VAO[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_2), vertices_2, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
		glClearColor(0.1f, 0.1f, 0.8f, 1.0f);        
        glClear(GL_COLOR_BUFFER_BIT);
		
		/* Activating shaders */
		glUseProgram(shaderProgram[0]);
		glBindVertexArray(VAO[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		
		glUseProgram(shaderProgram[1]);
		glBindVertexArray(VAO[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    
    return 0;
}
