#ifndef WINDOWSTERMINAL_HPP
#define WINDOWSTERMINAL_HPP

#include <core/Entity.hpp>
#include <core/Manager.hpp>
#include <core/Alias.hpp>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>

namespace EGE::STD::TERMINAL::WINDOWS{
    class Terminal : public EGE::CORE::Entity<Terminal>{
        private:
		/**Tamaño en x del tablero*/
		int width;

		/**Tamaño en y del tablero*/
		int tall;

		/**Instancia de Terminal*/
		static inline Terminal *terminal = nullptr;

		/**
		 *@brief Método constructor del tablero,
		 *@param width Tamaño en x del tablero.
		 *@param tall Tamaño en y del tablero.
		 */
		Terminal(int width, int tall);

        public:

		/**
		 * @brief Método que regresa una instancia de Terminal.
		 * @param x Tamaño en horizontal del tablero.
		 * @param y Tamaño en vertical del tablero.
		 * @return Instancia unica de terminal.
		 */
		static Terminal *getTerminal(int x,int y);

		/**
		 * @brief Método que regresa una instancia de Terminal.
		 * @return Instancia unica de terminal.
		 */
		static Terminal *getTerminal();

		/**
		 *@brief Método destructor de la clase.
		 */
		~Terminal();

		/**
		 *@brief Método que oculta el cursor de la terminal.
		 */
		void hideCursor();

		/**
		 *@brief Método que mueve el cursor en la temrinal.
		 *@param x Coordenada en x en la temrinal.
		 *@param y Coordenada en y en la temrinal.
		 */
		void gotoxy(int x, int y);

		/**
		 * @brief Método que define el color de los limites de la terminal y el fondo.
		 * @param color Color de los limites y del fondo.
		 */
		void setColor(unsigned short color);

		/**
		 *@brief Métdodo que pinta los limites del tablero.
		 *@param charHorizontal Caracter de las lineas horizontales del tablero.
		 *@param charVertical Caracter de las lineas verticales del tablero.
		 *@param charCorner1 Caracter de la esquina superior izquierda del tablero.
		 *@param charCorner2 Caracter de la esquina superior derecha del tablero.
		 *@param charCorner3 Caracter de la esquina inferiro izquierda del tablero.
		 *@param charCorner4 Carcter de la esquina inferiro derecha del tablero.
		 */
		void drawLimits(char charHorizontal,char charVertical, char charCorner1, char charCorner2, char charCorner3, char charCorner4);

		/**
		 * @brief Método que regresa el largo del tablero.
		 * @return Largo del tablero.
		 */
		int getWidth();

		/**
		 * @brief Método que regresa el alto de ltablero.
		 * @return Alto del tablero.
		 */
		int getTall();

		/**
		 * @brief Método que ejecuta funciones de rutina, con paramtros base.
		 */
		void init();
    };

	class mTerminal : public EGE::CORE::Manager<Terminal>{
		private:
			/**Bandera que indica si ya se creo la terminal*/
			bool isCreated = false;
		public:

			/**
			 * @brief Método encargado de agregar una terminal al manager.
			 * @param x Posición en x de la terminal.
			 * @param y Posición en y de la terminal.
			 * @return Identificador de la terminal.
			 */
			EGE::CORE::EntityId addEntity(int x, int y);

			/**
			 * @brief Método encargado de inicializr una terminal por default.
			 * @param id Identificador de la terminal.
			 */
			void terminalDefault(EGE::CORE::EntityId id);

			/**
			 * @brief Método encargado de de inicializar una terminal que se puede personalizar los limites.
			 * @param id Identificador de la terminal.
			 * @param charHorizontal Caracter de las lineas horizontales del tablero.
			 * @param charVertical Caracter de las lineas verticales del tablero.
			 * @param charCorner1 Caracter de la esquina superior izquierda del tablero.
			 * @param charCorner2 Caracter de la esquina superior derecha del tablero.
			 * @param charCorner3 Caracter de la esquina inferiro izquierda del tablero.
			 * @param charCorner4 Carcter de la esquina inferiro derecha del tablero.
			 */
			void terminalPersonalized(EGE::CORE::EntityId id,char charHorizontal = 205,char charVertical = 186, char charCorner1 = 201, char charCorner2 = 187, char charCorner3 = 200, char charCorner4 = 188);
			
			/**
			 * @brief Método encargado de definir el color de los limites y del fondo de la terminal.
			 * @param id Identificador de la terminal.
			 * @param color Color de los limites y de la terminal.
			 */
			void terminalSetColor(EGE::CORE::EntityId id, unsigned short color);
	};
}
#endif