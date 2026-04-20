#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include "GLEW/GL/glew.h"

// #include "imgui.h"
// #include "imgui_impl_glfw.h"
// #include "imgui_impl_opengl3.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

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


    // triangle co-ordinates
    float vertices[] = {
        0.5f, -0.5f, 0.0f,
       -0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    // generating vertex buffer object
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    // Setup Dear ImGui context
    // IMGUI_CHECKVERSION();
    // ImGui::CreateContext();
    // ImGuiIO& io = ImGui::GetIO();
    // io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Platform/Renderer backends
    // ImGui_ImplGlfw_InitForOpenGL(window, true); 
    // ImGui_ImplOpenGL3_Init();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        // ImGui_ImplOpenGL3_NewFrame();
        // ImGui_ImplGlfw_NewFrame();
        // ImGui::NewFrame();
        
		// ImGui::Begin("Test Window");
		// ImGui::Button("Click Me :)");
		// static float rotation = 0.0f;
		// ImGui::SliderFloat("Rotation", &rotation, 0.0, 2 * 3.14);
		// static float position[] = {0.0f, 0.0f};
		// ImGui::SliderFloat2("Position", position, -1.0, 1.0);	
		// static float color[4] = {0.2f, 0.5f, 0.6f, 1.0f};
		// ImGui::ColorEdit4("Color", color);

		// ImGui::End();

		// ImGui render here
        // ImGui::Render();
        // ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    // ImGui_ImplOpenGL3_Shutdown();
    // ImGui_ImplGlfw_Shutdown();
    // ImGui::DestroyContext();
    
    glfwTerminate();
    
    return 0;
}
