#include <stdafx.h>
#include "Shader.h"
#include "Resources.h"


Shader::Shader(ShaderResource* sr) {
	this->sr = sr;
}

int Shader::Init()
{

	vertexShader = esLoadShader(GL_VERTEX_SHADER, this->sr->vs_path);

	if (vertexShader == 0)
		return -1;

	fragmentShader = esLoadShader(GL_FRAGMENT_SHADER, this->sr->fs_path);

	if (fragmentShader == 0)
	{
		glDeleteShader(vertexShader);
		return -2;
	}

	program = esLoadProgram(vertexShader, fragmentShader);

	//finding location of uniforms / attributes
	positionAttribute = glGetAttribLocation(program, "a_posL");
	viewUniform = glGetUniformLocation(program, "u_view");
	perspectiveUniform = glGetUniformLocation(program, "u_persp");
	normAttribute = glGetAttribLocation(program, "a_norm");
	binormAttribute = glGetAttribLocation(program, "a_binorm");
	tgtAttribute = glGetAttribLocation(program, "a_tgt");

	//colorAttribute
	colorAttribute = glGetAttribLocation(program, "a_color");
	matrixUniform = glGetUniformLocation(program, "u_rotZ");

	uvAttribute = glGetAttribLocation(program, "a_uv");
	textureUniform = glGetUniformLocation(program, "u_texture");
	return 0;
}

Shader::~Shader()
{
	glDeleteProgram(program);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}