#version 330 core

in vec3 texColor;
in vec2 texCoord;
out vec4 FragColor;

// uniform sampler2D ourTexture;

// void main()
// {
//     FragColor = texture(ourTexture, texCoord) * vec4(texColor, 1.0f);
// }

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    FragColor = mix(texture(texture1, texCoord), texture(texture2, texCoord), 0.3);
}