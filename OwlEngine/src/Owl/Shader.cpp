#include "oepch.h"
#include "Shader.h"

namespace OE {

	Shader::Shader()
	{
	}


	Shader::~Shader()
	{
	}

	void Shader::init(const GLchar * filename)
	{
		allOk = false;
		std::string path = filename;
		std::string vertexShaderPath = path + ".sv";
		std::string fragmentShaderPath = path + ".sf";

		std::string vShaderSource, fShaderSource;

		std::fstream sv, sf;


		// Load vertex and fragment shaders.
		sv.open(vertexShaderPath, std::fstream::in);

		if (sv.is_open())
		{
			std::string tempString;
			while (!sv.eof())
			{
				std::getline(sv, tempString);

				vShaderSource = tempString + "\n";
			}
		}

		const GLchar* svSource = vShaderSource.c_str();

		sf.open(fragmentShaderPath, std::fstream::in);

		if (sf.is_open())
		{
			std::string tempString;
			while (!sf.eof())
			{
				std::getline(sf, tempString);

				fShaderSource = tempString + "\n";
			}
		}
		
		const GLchar* sfSource = fShaderSource.c_str();
		

		int success;
		char infoLog[512];

		// Compile vertex shader.
		int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &svSource, NULL);
		glCompileShader(vertexShader);
		
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);

			std::cout << "Error: " << infoLog << std::endl;
		}

		// Compile fragment shader.
		int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &sfSource, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);

			std::cout << "Error: " << infoLog << std::endl;
		}

		// Create shader program.
		if (success)
		{
			allOk = true;

			idProgram = glCreateProgram();
			glAttachShader(idProgram, vertexShader);
			glAttachShader(idProgram, fragmentShader);
			glLinkProgram(idProgram);
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

}