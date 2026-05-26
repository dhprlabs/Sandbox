#version 330 core

in vec3 ourColor;
out vec4 FragColor;

uniform vec4 sineColor;

void main()
{
    // FragColor = sineColor;    // setting the uniform variable from code globally
    FragColor = vec4(ourColor, 1.0);
}