#pragma once
#include "Core.h"
#include "Texture.h"

namespace OE
{
	/**
	* @class TextureManager
	* @brief Se encarga del cargado y edici�n de las texturas.
	* 
	* Esta clase permite cargar texturas, las almacena en RAM y permite recortar spritesheets y tilemaps.
	*/
	class OWL_API TextureManager
	{
	private:
		static TextureManager* instance;

		std::vector<Texture*> texturePool; /*!< Contiene las texturas cargadas en RAM.*/
		std::map<std::string, int> idMap; /*!< vincula la ruta de la textura con su ID.*/
		int freeFirstSlot; /*!< Guarda la primera posici�n libre en el texturePool.*/

		/**
		* Esta funci�n nos permite cargar una textura a partir de una ruta.
		* @param _path es la ruta donde se encuentra la imagen.
		*/
		unsigned int createTexture(std::string _path); 

		/**
		* Actualizar la primera posici�n libre de la texturePool.
		* @return La primera posici�n libre de la texturePool actual.
		*/
		int updateFirstFreeSlot();
	protected:
		TextureManager();
	public:
		/**
		* Esta funci�n nos da la instancia de la clase.
		*/
		static TextureManager* getInstance();
		
		/**
		* Esta funci�n nos da el id de la imagen a partir de su ruta.
		* @param ruta de la imagen.
		* @return ID de la imagen.
		*/
		unsigned int getTextureID(std::string _path);

		/**
		* Esta funci�n nos da la textura a partir de su ID.
		*@param ID de la textura.
		*@retrun El puntero de una instancia de Texture.
		*/
		Texture* getTextureByID(unsigned int _id);

		/**
		* Esta funci�n nos permite dividir la textura en varias texturas.
		* @parm ID de la textura a dividir.
		* @param Alto del tile o sprite.
		* @param Ancho del tile o sprite.
		*/
		void sliceTexture(unsigned int _id, int _tileHeight, int _tileWidth);
		~TextureManager();
	};
}
