#include "oepch.h"
#include "TextureManager.h"

namespace OE
{
	TextureManager* TextureManager::instance = NULL;

	unsigned int TextureManager::createTexture(std::string _path)
	{
		SDL_Surface* tempSuface = IMG_Load(_path.c_str());

		Texture* tempTexture = new Texture();

		tempTexture->setHeight(tempSuface->h);
		tempTexture->setWidth(tempSuface->w);

		glBindTexture(GL_TEXTURE_2D, tempTexture->id);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tempTexture->getWidth(), tempTexture->getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tempSuface->pixels);

		glGenerateMipmap(GL_TEXTURE_2D);

		SDL_FreeSurface(tempSuface);
		
		if (freeFirstSlot >= texturePool.size())
		{
			texturePool.push_back(tempTexture);

			int id = freeFirstSlot;

			updateFirstFreeSlot();

			return id;
		}
	}

	int TextureManager::updateFirstFreeSlot()
	{
		return freeFirstSlot;
	}

	TextureManager::TextureManager()
	{
	}


	TextureManager * TextureManager::getInstance()
	{
		if (instance == NULL)
		{
			instance = new TextureManager();
		}

		return instance;
	}

	unsigned int TextureManager::getTextureID(std::string _path)
	{
		std::map<std::string, int>::iterator it = idMap.find(_path);
		if (it == idMap.end())
		{
			return createTexture(_path);
		}
		else
		{
			if (it->first == _path)
			{
				return it->second;
			}
		}
	}

	Texture * TextureManager::getTextureByID(unsigned int _id)
	{
		return nullptr;
	}

	void TextureManager::sliceTexture(unsigned int _id, int _tileHeight, int _tileWidth)
	{
	}

	TextureManager::~TextureManager()
	{
	}
}