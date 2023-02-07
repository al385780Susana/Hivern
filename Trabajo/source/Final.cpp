#include <nds.h>
#include <stdio.h>
#include <time.h>
#include "gameOver.h"
#include "hasGanado.h"
#include "portada.h"
#include "inicio.h"






u8 t_jugador[64] =
{
	3,5,3,5,3,3,2,5,
	5,5,3,5,5,3,5,5,
	5,5,5,5,5,3,5,5,
	5,0,5,0,5,3,5,5,
	5,5,5,5,3,5,5,5,
	3,5,5,5,3,5,5,5,
	2,5,5,5,5,5,5,2,
	0,5,0,5,0,5,0,3,
};

u8 t_jmedio[64] =
{
	6,5,3,5,3,3,6,5,
	5,5,3,5,5,3,5,5,
	5,5,5,5,5,3,5,5,
	5,0,5,0,5,3,5,5,
	5,5,5,5,3,5,5,5,
	3,5,5,5,3,5,5,5,
	6,5,5,5,5,5,5,6,
	0,5,0,5,0,5,0,6,
};


u8 t_jdificil[64] =
{
	4,5,4,5,4,4,7,5,
	5,5,4,5,5,4,5,5,
	5,5,5,5,5,4,5,5,
	5,0,5,0,5,4,5,5,
	5,5,5,5,4,5,5,5,
	4,5,5,5,4,5,5,5,
	4,5,5,5,5,5,5,4,
	0,5,0,5,0,5,0,4,
};


u8 t_inicial[64] =
{
	3,3,3,3,3,3,2,2,
	3,3,3,3,3,3,3,3,
	2,2,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,
	2,2,3,3,3,3,2,2,
	3,3,3,3,3,3,3,3,
};

u8 t_medio[64] =
{
	6,6,3,3,3,3,6,6,
	6,6,3,3,3,3,6,6,
	3,3,3,3,3,3,3,3,
	3,3,3,6,6,3,3,3,
	3,3,3,6,6,3,3,3,
	3,3,3,3,3,3,3,3,
	6,6,3,3,3,3,6,6,
	6,6,3,3,3,3,6,6,
};

u8 t_dificil[64] =
{
	4,7,4,4,4,4,7,4,
	4,7,4,4,4,4,7,4,
	4,4,7,4,4,7,4,4,
	4,4,7,4,4,7,4,4,
	4,7,4,4,4,4,4,4,
	4,7,4,4,4,7,4,4,
	4,4,4,4,4,7,7,4,
	4,4,4,4,4,4,7,4,
};


u8 t_bellota[64] =
{
	3,3,3,3,3,3,9,9,
	3,9,9,9,9,9,9,3,
	8,8,9,9,9,9,9,9,
	8,8,8,8,8,9,9,9,
	8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,2,
	8,8,8,8,8,3,3,3,
};

u8 t_bellotamedio[64] =
{
	6,6,3,3,3,3,9,9,
	6,9,9,9,9,9,9,3,
	8,8,9,9,9,9,9,9,
	8,8,8,8,8,9,9,9,
	8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,6,
	8,8,8,8,8,3,6,6,
};

u8 t_bellotadificil[64] =
{
	4,7,4,4,4,4,9,9,
	4,9,9,9,9,9,9,4,
	8,8,9,9,9,9,9,9,
	8,8,8,8,8,9,9,9,
	8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,4,
	8,8,8,8,8,4,7,4,
};

u8 t_enemigo[64] =
{
	2,0,0,3,3,3,3,3,
	0,1,0,0,3,3,3,3,
	3,0,0,0,3,3,2,2,
	3,3,0,0,3,3,3,3,
	3,3,0,0,3,3,3,3,
	3,3,3,0,0,0,0,3,
	3,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
};



u8 t_enemigo_medio[64] =
{

	2,0,0,3,3,3,6,6,
	0,1,0,0,3,3,6,6,
	3,0,0,0,3,3,2,2,
	3,3,0,0,6,3,3,3,
	3,3,0,0,6,3,3,3,
	3,3,3,0,0,0,0,3,
	6,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
};

u8 t_enemigo_dificil[64] =
{

	2,0,0,4,4,4,7,4,
	0,1,0,0,4,4,7,4,
	4,0,0,0,4,7,2,2,
	4,4,0,0,4,7,4,4,
	4,7,0,0,4,4,4,4,
	4,7,4,0,0,0,0,4,
	4,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
};




//zona 6 -> zona media, -2s
//zona 4 -> zona facil, -1s
//zona 3/5 -> zona dificil, -3s

//4 inicial, 5 medio, 6 dificil

u16 mapData[768] =
{
	5,5,5,5,5,5,5,5, 5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5, 5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5, 6,6,6,6,6,5,5,5,  5,5,5,6,6,6,6,6, 5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5, 6,6,6,6,6,6,6,6,  6,6,6,6,6,6,6,6, 5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5, 6,6,6,6,6,6,6,6,  6,6,6,6,6,6,6,6, 5,5,5,5,5,5,5,5,

	5,5,6,6,6,6,6,6, 5,5,5,5,5,5,6,6,  6,6,5,5,5,5,5,5, 6,6,6,6,6,6,5,5,
	5,5,6,6,6,6,6,6, 5,5,5,5,5,5,6,6,  6,6,5,5,5,5,5,5, 6,6,6,6,6,6,5,5,
	5,5,5,5,5,5,5,5, 5,5,5,5,6,6,6,6,  6,6,6,6,5,5,5,5, 5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5, 6,6,6,6,6,6,6,6,  6,6,6,6,6,6,6,6, 5,5,5,5,5,5,5,5,

	5,5,5,5,5,5,5,5, 6,6,6,6,6,6,4,4,  4,4,6,6,6,6,6,6, 5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5, 6,6,6,6,6,4,4,4,  4,4,4,6,6,6,6,6, 5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5, 6,6,6,6,4,4,4,4,  4,4,4,4,6,6,6,6, 5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5, 6,6,6,6,4,4,4,4,  4,4,4,4,6,6,6,6, 5,5,5,5,5,5,5,5,

	5,5,5,5,5,5,5,5, 6,6,6,6,4,4,4,4,  4,4,4,4,6,6,6,6, 5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5, 6,6,6,6,4,4,4,4,  4,4,4,4,6,6,6,6, 5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5, 6,6,6,6,6,4,4,4,  4,4,4,6,6,6,6,6, 5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5, 6,6,6,6,6,6,4,4,  4,4,6,6,6,6,6,6, 5,5,5,5,5,5,5,5,

	5,5,5,5,5,5,5,5, 6,6,6,6,6,6,6,6,  6,6,6,6,6,6,6,6, 5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5, 5,5,5,5,6,6,6,6,  6,6,6,6,5,5,5,5, 5,5,5,5,5,5,5,5,
	5,5,6,6,6,6,6,6, 5,5,5,5,5,5,6,6,  6,6,5,5,5,5,5,5, 6,6,6,6,6,6,5,5,
	5,5,6,6,6,6,6,6, 5,5,5,5,5,5,6,6,  6,6,5,5,5,5,5,5, 6,6,6,6,6,6,5,5,

	5,5,5,5,5,5,5,5, 6,6,6,6,6,6,6,5,  5,6,6,6,6,6,6,6, 5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5, 6,6,6,6,6,6,5,5,  5,5,6,6,6,6,6,6, 5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5, 6,6,6,6,6,5,5,5,  5,5,5,6,6,6,6,6, 5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5, 5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5, 5,5,5,5,5,5,5,5,

};									 


//DECLARACIÓN DE VARIABLES Y FUNCIONES

//Modo teselado y modo framebuffer
void Tiles();
void Framebuffer();


void int_timer();
void int_timer2();
void int_timer3();
void int_timerEnemigos();

void Inicio();
void GameOver();
void Win();
void Portada();

void InterrupcionesJuego();
void Juego();
void ColocarBellotas();
void Enemigos();
void MoverEnemigos();
void MovimientoPj();
void DibujarPj();
void DibujarNextPj();

void ActualizarRecord();
void LimpiarTexto();

int columnaPJ;
int filaPJ;
int filaenemigo;
int columenemigo;

int fila;
int columna;
int pos_mapMemory;
int pos_mapData;
static u16* mapMemory;


int record;
int tiempo;
int tiempo2;
int cambio;
int bellotas;
int estado;
bool nuevoRecord;


//Modo teselado
void Tiles()
{
	//TESELAS
	REG_POWERCNT = POWER_ALL_2D;
	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE;
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	BGCTRL[0] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1);

	static u8*  tileMemory = (u8*)BG_TILE_RAM(1);
	mapMemory = (u16*)BG_MAP_RAM(0);

	BG_PALETTE[0] = RGB15(0, 0, 0); // Negro
	BG_PALETTE[1] = RGB15(31, 31, 31); // Blanco
	BG_PALETTE[2] = RGB15(31, 31, 10); // Amarillo
	BG_PALETTE[3] = RGB15(20, 31, 20); //Verde
	BG_PALETTE[4] = RGB15(30, 30, 31); // Gris azulado
	BG_PALETTE[5] = RGB15(30, 15, 0); // Marrón
	BG_PALETTE[6] = RGB15(25, 31, 25); // verde claro
	BG_PALETTE[7] = RGB15(25, 25, 25); // Gris
	BG_PALETTE[8] = RGB15(31, 20, 0); // Marrón claro
	BG_PALETTE[9] = RGB15(31, 5, 0); // Marrón oscuro


	dmaCopy(t_jugador, tileMemory, sizeof(t_jugador));	//0
	dmaCopy(t_jmedio, tileMemory + 64, sizeof(t_jmedio));		//1
	dmaCopy(t_jdificil, tileMemory + 128, sizeof(t_jdificil));	//2
	dmaCopy(t_bellota, tileMemory + 192, sizeof(t_bellota));	//3
	dmaCopy(t_inicial, tileMemory + 256, sizeof(t_inicial));	//4
	dmaCopy(t_medio, tileMemory + 320, sizeof(t_medio));	//5
	dmaCopy(t_dificil, tileMemory + 384, sizeof(t_dificil)); //6
	dmaCopy(t_enemigo, tileMemory + 448, sizeof(t_enemigo)); //7
	dmaCopy(t_enemigo_medio, tileMemory + 512, sizeof(t_enemigo_medio)); //8
	dmaCopy(t_enemigo_dificil, tileMemory + 576, sizeof(t_enemigo_dificil)); //9
	dmaCopy(t_bellotamedio, tileMemory + 640, sizeof(t_bellotamedio));	//10
	dmaCopy(t_bellotadificil, tileMemory + 704, sizeof(t_bellotadificil));	//11

	pos_mapData = 0;
	for (fila = 0; fila < 24; fila++)
		for (columna = 0; columna < 32; columna++)
		{
			pos_mapMemory = fila * 32 + columna;
			mapMemory[pos_mapMemory] = mapData[pos_mapData];
			pos_mapData++;
		}

}

//Modo framebuffer
void Framebuffer()
{
	REG_POWERCNT = POWER_LCD | POWER_2D_A;

	VRAM_A_CR = VRAM_ENABLE | VRAM_A_LCD;
	dmaCopy(portadaBitmap, VRAM_A, 256 * 192 * 2);

	VRAM_B_CR = VRAM_ENABLE | VRAM_B_LCD;
	dmaCopy(inicioBitmap, VRAM_B, 256 * 192 * 2);

	VRAM_C_CR = VRAM_ENABLE | VRAM_C_LCD;
	dmaCopy(hasGanadoBitmap, VRAM_C, 256 * 192 * 2);

	VRAM_D_CR = VRAM_ENABLE | VRAM_D_LCD;
	dmaCopy(gameOverBitmap, VRAM_D, 256 * 192 * 2);


}


void ActualizarRecord()
{
	if (bellotas > record) 
	{ 
		record = bellotas; 
		bellotas = 0;
		nuevoRecord = true;
	}

}

//TIMERS

//Timer zona 1 (tile 4) donde el tiempo se reduce en 1 cada segundo
void int_timer()
{
	tiempo--;
}

//Timer zona 2 (tile 5) donde el tiempo se reduce en 2 cada segundo
void int_timer2()
{
	tiempo -= 2;
}

//Timer zona 3 (tile 6) donde el tiempo se reduce en 3 cada segundo
void int_timer3()
{
	tiempo -= 3;
}

//Timer para el movimiento de los enemigos (se mueven cada segundo)
void int_timerEnemigos()
{
	tiempo2++;
}



//Pantalla inicio
void Inicio() //estado = 1;
{
	//las variables se ponen en su valor inicial
	tiempo = 60;
	tiempo2 = 0;
	cambio = 0;
	bellotas = 0;

	//el estado pasa a ser 1
	estado = 1;

	//la imagen es la de la pantalla de inicio
	REG_DISPCNT = MODE_FB1;
}

//Pantalla Game Over
void GameOver()
{

	//se deshabilitan los timer
	irqDisable(IRQ_TIMER0);
	irqDisable(IRQ_TIMER1);

	//se comprueba si hay nuevo record
	ActualizarRecord();

	//el estado pasa a ser 4
	estado = 4;

	//la imagen es la de pantalla de game over
	REG_DISPCNT = MODE_FB3;

}

//Pantalla victoria
void Win()
{
	//se deshabilitan los timer
	irqDisable(IRQ_TIMER0);
	irqDisable(IRQ_TIMER1);

	//se comprueba si hay nuevo record
	ActualizarRecord();

	//el estado pasa a ser 3
	estado = 3;
	
	//la imagen es la de pantalla de victoria
	REG_DISPCNT = MODE_FB2;

}


void InterrupcionesJuego()
{
	//estado pasa a ser 2
	estado = 2;

	//INTERRUPCIONES CRUCETA
	irqSet(IRQ_KEYS, MovimientoPj);
	irqEnable(IRQ_KEYS);
	REG_KEYCNT = 0x40F0;			//100000011110000

	//Timers habilitados
	irqEnable(IRQ_TIMER0);
	irqEnable(IRQ_TIMER1);
	irqSet(IRQ_TIMER0, int_timer);
	irqSet(IRQ_TIMER1, int_timerEnemigos);

	nuevoRecord = false; //se pone a false ya que se va a comenzar nueva partida

	//MAPA SE RESETEA
	pos_mapData = 0;
	for (fila = 0; fila < 24; fila++)
		for (columna = 0; columna < 32; columna++)
		{
			pos_mapMemory = fila * 32 + columna;
			mapMemory[pos_mapMemory] = mapData[pos_mapData];
			pos_mapData++;
		}

	Juego();


}

void Juego()
{

	//SE COLOCA PJ
	filaPJ = 12;
	columnaPJ = 16;
	mapMemory[filaPJ * 32 + columnaPJ] = 0;

	ColocarBellotas();
	Enemigos();

}


void MovimientoPj()
{
	if (REG_KEYINPUT == 0X3DF && columnaPJ > 0) //LEFT
	{
		DibujarPj();

		columnaPJ -= 1;

		DibujarNextPj();
	}



	if (REG_KEYINPUT == 0x3EF && columnaPJ < 31)	//RIGHT
	{
		DibujarPj();

		columnaPJ += 1;

		DibujarNextPj();
	}

	if (REG_KEYINPUT == 0x3BF && filaPJ > 0)	//UP
	{
		DibujarPj();


		filaPJ -= 1;


		DibujarNextPj();

	}

	if (REG_KEYINPUT == 0x37F && filaPJ < 23)	//DOWN
	{
		DibujarPj();

		filaPJ += 1;
		
		DibujarNextPj();

	}


}

//Dibuja la tile del personaje correcta en la posición donde está
void DibujarPj()
{
	if (mapMemory[filaPJ * 32 + columnaPJ] == 0)	//si el PJ es 0 (está en zona1)
	{
		mapMemory[filaPJ * 32 + columnaPJ] = 4;	//donde estaba el jugador se pone t_inicial
	}
	else if (mapMemory[filaPJ * 32 + columnaPJ] == 1)	//t_jmedio
	{
		mapMemory[filaPJ * 32 + columnaPJ] = 5;	//t_medio
	}
	else if (mapMemory[filaPJ * 32 + columnaPJ] == 2)	//t_jdificil
	{
		mapMemory[filaPJ * 32 + columnaPJ] = 6;	//t_dificil
	}
}

//Dibujar en la siguiente tesela el personaje correcto
void DibujarNextPj()
{
	//SI NO CHOCA CON NADA
	if (mapMemory[filaPJ * 32 + columnaPJ] == 4) //si es t_inicial
	{
		mapMemory[filaPJ * 32 + columnaPJ] = 0;	//pj inicial

		irqSet(IRQ_TIMER0, int_timer);
	}
	else if (mapMemory[filaPJ * 32 + columnaPJ] == 5)	//t_medio
	{
		mapMemory[filaPJ * 32 + columnaPJ] = 1;	//pj medio

		irqSet(IRQ_TIMER0, int_timer2);
	}
	else if (mapMemory[filaPJ * 32 + columnaPJ] == 6)	//t_dificil
	{
		mapMemory[filaPJ * 32 + columnaPJ] = 2;	//pj dificil

		irqSet(IRQ_TIMER0, int_timer3);
	}
	
	//SI CHOCA CON BELLOTA
	else if (mapMemory[filaPJ * 32 + columnaPJ] == 3) //bellota
	{
		mapMemory[filaPJ * 32 + columnaPJ] = 0;	//pj inicial
		bellotas += 1;

		irqSet(IRQ_TIMER0, int_timer);
	}

	else if (mapMemory[filaPJ * 32 + columnaPJ] == 10) //bellotamedio
	{
		mapMemory[filaPJ * 32 + columnaPJ] = 1;	//pj medio
		bellotas += 1;

		irqSet(IRQ_TIMER0, int_timer2);
	}

	else if (mapMemory[filaPJ * 32 + columnaPJ] == 11) //bellotadificil
	{
		mapMemory[filaPJ * 32 + columnaPJ] = 2;	//pj dificil
		bellotas += 1;

		irqSet(IRQ_TIMER0, int_timer3);
	}

	//SI CHOCA CON SERPIENTE
	else if (mapMemory[filaPJ * 32 + columnaPJ] == 7|| mapMemory[filaPJ * 32 + columnaPJ] == 8 || mapMemory[filaPJ * 32 + columnaPJ] == 9) //ENEMIGO
	{
		GameOver();//estado 4
	}



}


void LimpiarTexto()
{
	for (int i = 0; i < 24; i++)
	{
		iprintf("\x1b[i;2H                                              ");
	}
}


//Función para colocar las bellotas aleatorias
void ColocarBellotas()
{
	int bfil;
	int bcol;
	int repetir;

	for (int i = 0; i < 25; i++)	//DE MOMENTO 25
	{

		repetir = 1;
		while (repetir == 1)
		{
			bcol = rand() % 32;
			bfil = rand() % 23;
			pos_mapMemory = bfil * 32 + bcol;
			// si ya hay algo en la pantalla repite, si no la hay (es fondo) dibuja el objeto y sale
			if (mapMemory[bfil * 32 + bcol] == 4)	//t_inicial
			{
				mapMemory[bfil * 32 + bcol] = 3; //bellota
				repetir = 0;
			}
			else if (mapMemory[bfil * 32 + bcol] == 5)	//t_medio
			{
				mapMemory[bfil * 32 + bcol] = 10; //bellotamedio
				repetir = 0;
			}
			else if (mapMemory[bfil * 32 + bcol] == 6)	//t_dif
			{
				mapMemory[bfil * 32 + bcol] = 11; //bellotadif
				repetir = 0;
			}
		}
	}
}

//Función para colocar enemigos aleatorios
void Enemigos()
{
	int efil;
	int ecol;
	int repetir;

	for (int i = 0; i < 20; i++)	//DE MOMENTO 20
	{

		repetir = 1;
		while (repetir == 1)
		{
			ecol = rand() % 32;
			efil = rand() % 23;
			pos_mapMemory = efil * 32 + ecol;

			// si ya hay algo en la pantalla repite, si no la hay (es fondo) dibuja el objeto y sale. No aparecen en la zona del centro (tile 4)
			if (mapMemory[efil * 32 + ecol] == 5)	//t_medio
			{
				mapMemory[efil * 32 + ecol] = 8; //enemigomedio
				repetir = 0;
			}
			else if (mapMemory[efil * 32 + ecol] == 6)	//t_dif
			{
				mapMemory[efil * 32 + ecol] = 9; //enemigodif
				repetir = 0;
			}
		}
	}
}


//Función movimiento enemigo
//Comprueba la tile actual, pone la tile toca, comprueba la tile columna -1 y pone la serpiente que toca. En el caso columna == 0 pone la tile que toca, y pone en columna == 32 la serpiente toca 
void MoverEnemigos()
{
	for (fila = 0; fila <= 23; fila++)
	{

		for (columna = 0; columna <= 32; columna++)
		{
			//Si la columna es 0 entonces, si hay serpiente copiala en la misma línea columna 31 (loop)
			if(columna == 0)
			{
				if (mapMemory[fila * 32 + 0] == 8)
				{
					mapMemory[fila * 32 + columna] = 5;
					columna = 31;
					if (fila == 0) { fila = 23; }
					mapMemory[fila * 32 + columna] = 8;
					columna = 0;
				}
			}

			else if (mapMemory[fila * 32 + columna] == 7) //enemigo
			{
				mapMemory[fila * 32 + columna] = 4;	//t_inicial

				if (mapMemory[fila * 32 + columna - 1] == 4 || mapMemory[fila * 32 + columna - 1] == 3) //bellota/t_inicial
				{
					mapMemory[fila * 32 + columna - 1] = 7; //enemigo inicial
				}

				if (mapMemory[fila * 32 + columna - 1] == 5 || mapMemory[fila * 32 + columna - 1] == 10) //t_medio//bellotamedio
				{
					mapMemory[fila * 32 + columna - 1] = 8;	//enemigomedio

				}

				else if (mapMemory[fila * 32 + columna - 1] == 6 || mapMemory[fila * 32 + columna - 1] == 11) //t_dif/belldif
				{
					mapMemory[fila * 32 + columna - 1] = 9;	//enemigodif

				}

				//COLISIÓN
				else if (mapMemory[fila * 32 + columna - 1] == 0 || mapMemory[fila * 32 + columna - 1] == 2)
				{
					GameOver();
				}
	
			}

			else if (mapMemory[fila * 32 + columna] == 8) //enemigo medio
			{
				mapMemory[fila * 32 + columna] = 5;	//t_medio

				if (mapMemory[fila * 32 + columna - 1] == 4 || mapMemory[fila * 32 + columna - 1] == 3) //t_inicial
				{
					mapMemory[fila * 32 + columna - 1] = 7; //enemigo inicial
				}

				else if (mapMemory[fila * 32 + columna - 1] == 5 || mapMemory[fila * 32 + columna - 1] == 10) //t_medio
				{

					mapMemory[fila * 32 + columna - 1] = 8;	//enemigomedio

				}
				else if (mapMemory[fila * 32 + columna - 1] == 6 || mapMemory[fila * 32 + columna - 1] == 11) //t_dif
				{
					mapMemory[fila * 32 + columna - 1] = 9;	//enemigodif

				}

				//COLISIÓN
				else if (mapMemory[fila * 32 + columna - 1] == 1 || mapMemory[fila * 32 + columna - 1] == 2)
				{
					GameOver();
				}
			}

			else if (mapMemory[fila * 32 + columna] == 9) //enemigo dif
			{
				mapMemory[fila * 32 + columna] = 6;	//t_dif
				if (mapMemory[fila * 32 + columna - 1] == 6 || mapMemory[fila * 32 + columna - 1] == 11) //t_dif
				{
					mapMemory[fila * 32 + columna - 1] = 9;	//enemigodif

				}
				else if (mapMemory[fila * 32 + columna - 1] == 4 || mapMemory[fila * 32 + columna - 1] == 3) //t_inicial
				{
					mapMemory[fila * 32 + columna - 1] = 7;	//enemigo

				}

				else if (mapMemory[fila * 32 + columna - 1] == 5 || mapMemory[fila * 32 + columna - 1] == 10) //t_media
				{
					mapMemory[fila * 32 + columna - 1] = 8;	//enemigomedi

				}

				//COLISIÓN
				else if (mapMemory[fila * 32 + columna - 1] == 0 || mapMemory[fila * 32 + columna - 1] == 1 || mapMemory[fila * 32 + columna - 1] == 2)
				{
					GameOver();
				}

			}

		}
	}
}



int main(void)
{
	//Posición PJ
	filaPJ = 12;
	columnaPJ = 16;


	//TIMER
	//timer inicial (zona central, tile 4)
	TIMER_DATA(0) = 32764;	//1s
	TIMER_CR(0) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ;

	//timer enemigos
	TIMER_DATA(1) = 32764;	//1s
	TIMER_CR(1) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ;


	//Comineza el framebuffer con la imagen de portada
	Framebuffer();
	REG_DISPCNT = MODE_FB0;
	estado = 0;

	//Consulta de estado (mientras no pulses A no continua y sigue en la portada)
	while (REG_KEYINPUT != 0x03FE){}


	//Valores iniciales de las variables
	bellotas = 0;
	record = 0;
	tiempo = 60; //1 min de partida
	tiempo2 = 0;
	cambio = 0;
	nuevoRecord = false; //empieza en falso


	while (1)
	{
		//estados, 0=portada, 1=inicio, 2=juego, 3=win, 4=gameover
		
		//Si no está en el juego (estado 2)
		if (estado != 2)
		{	
			//Modo framebuffer
			Framebuffer();

			scanKeys();
			int down = keysDown();

			//Si pulsas A
			if (down & KEY_A)
			{
				//Si está en la portada, pantalla de victoria o pantalla game over pasa a la pantalla de inicio
				if (estado == 0 || estado == 3 || estado == 4)
				{
					Inicio(); 
				}
				//Si está en la pantalla de inicio empieza el juego
				else if (estado == 1) 
				{
					//Modo teselado
					Tiles(); 
					//Comienza el juego
					InterrupcionesJuego();
				}
				
			}
			
		
			
		
		}

		else if(estado == 2) //juego
		{
			consoleDemoInit();

			//RECORD Y CONTADOR
			iprintf("\x1b[2;2HTiempo restante = %d     ", tiempo);
			iprintf("\x1b[6;2HBellotas recogidas = %d   ", bellotas);
			iprintf("\x1b[22;2HRecord bellotas = %d   ", record);

			//Mensaje si consigues superar tu record
			if (bellotas>record)
			{ 
				iprintf("\x1b[13;9H--------------  ");
				iprintf("\x1b[15;9HNuevo record   "); 
				iprintf("\x1b[17;9H--------------  ");
			}


			//Movimiento enemigo, cada 1 segundo
			if (tiempo2 >= cambio)
			{
				MoverEnemigos();
				cambio++;
			}



			if(tiempo<=0) //si la cuenta atrás se acaba
			{
				Win();
			}

		}

		
		swiWaitForVBlank();
	}


}
