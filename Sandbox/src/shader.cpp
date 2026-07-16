#include "shader.h"


Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexShader;
	std::ifstream vertexShaderFile;

	std::string fragmentShader;
	std::ifstream fragmentShaderFile;

	try
	{
        vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		std::stringstream vertexStream, fragmentStream;

		vertexShaderFile.open(vertexPath);
		vertexStream << vertexShaderFile.rdbuf();

		fragmentShaderFile.open(fragmentPath);
		fragmentStream << fragmentShaderFile.rdbuf();

		vertexShaderFile.close();
		vertexShader = vertexStream.str();

		fragmentShaderFile.close();
		fragmentShader = fragmentStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "[SHADER ERROR]: " << e.what() << "\n";
	}

	const char* vertexShaderCode = vertexShader.c_str();
	const char* fragmentShaderCode = fragmentShader.c_str();

    unsigned int vs;
    vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertexShaderCode, NULL);
    glCompileShader(vs);

    unsigned int fs;
    fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragmentShaderCode, NULL);
    glCompileShader(fs);

    int success;
    char infoLog[512];

    glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vs, 512, NULL, infoLog);
        std::cout << "[VERTEX SHADER ERROR]: " << infoLog << std::endl;
    }

    glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fs, 512, NULL, infoLog);
        std::cout << "[FRAGMENT SHADER ERROR]: " << infoLog << std::endl;
    }

    shaderId = glCreateProgram();
    glAttachShader(shaderId, vs);
    glAttachShader(shaderId, fs);
    glLinkProgram(shaderId);

    glDeleteShader(vs);
    glDeleteShader(fs);
}


void Shader::use()
{
    glUseProgram(shaderId);
}


void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(shaderId, name.c_str()), value);
}


void Shader::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(shaderId, name.c_str()), value);
}

void Shader::setMat4(const std::string& name, glm::mat4 mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(shaderId, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::setVec3(const std::string& name, float x, float y, float z) const
{
    glUniform3f(glGetUniformLocation(shaderId, name.c_str()), x, y, z);
}
