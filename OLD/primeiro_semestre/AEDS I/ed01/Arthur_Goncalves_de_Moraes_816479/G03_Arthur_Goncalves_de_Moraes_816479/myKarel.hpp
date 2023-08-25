/*
myKarel - v0.1 
Author: Arthur Goncalves de Moraes - 816479
*/
#include "karel.hpp"

//--------------------------------- mundo

void BHWall(int X1, int X2, int Y)//Biuld Horizontal Wall ( X start, X end, Y position)
{if(Y>=1 && Y<=10 || !X2>=1 && !X2<=10){for (X1;X1<=X2;X1++){world->set ( X1, Y, HWALL );}}}// horizontal

void BVWall(int X, int Y1, int Y2) //Biuld Vertical Wall ( X position, Y start, Y end)
{if(!Y2>=1 && !Y2<=10 || X>=1 && X<=10){for (Y1;Y1<=Y2;Y1++){world->set ( X, Y1, VWALL );}}}// vertical

void BRectangle(int X1, int Y1,int X2, int Y2)//Biuld Rectangle
{BHWall(X1,X2,Y1);BHWall(X1,X2,Y2-1);BVWall(X1-1,Y2,Y1);BVWall(X2,Y2,Y1);}


//--------------------------------- robo

/**
MyTurnRight - Procedimento (acao) para virar 'a direita.
*/
void MyTurnRight ( )
{
// testar se o robo esta' ativo
if ( checkStatus ( ) )
{
// o agente que executar esse metodo
// devera' virar tres vezes 'a esquerda
turnLeft ( );
turnLeft ( );
turnLeft ( );
} // end if
} // end MyTurnRight ( )
/**
MyMoveN - Metodo para mover certa quantidade de passos.
@param steps - passos a serem dados.
*/
void MyMoveN( int steps )
{
	// definir dado local
	int step = 0;
	// repetir contando e testando ate' atingir a quantidade de passos
	if(steps>=1){
		for ( step = 1; step <= steps; step = step + 1 ) // outra forma de repetir
		{
		// dar um passo por vez
			move( );
		} // end if
	}else
	{
			turnLeft();turnLeft();//180°
			for ( step = -1; step >= steps; step = step - 1 ) // outra forma de repetir
		{
		// dar um passo por vez
			move( );
		} // end if
			turnLeft();turnLeft();//180°
	}
} // end MyMoveN( )
void myWalkTurnLeftWalk (int x, int y)//andar x vezes, virar a esquerda, andar y vezes, virar direita
{
	MyMoveN( x );
	turnLeft( );
	MyMoveN( y );
	MyTurnRight( );
}
void putBeepers (int X)
{
	if ( nbeepers( ) > 0 )
	{
	// ... de tentar descarrega-lo
	while(X>0){X--;putBeeper( );}
	} // end if
}

void putAllIfHave ()
{
	while ( nbeepers( ) > 0 )
	{
	// ... de tentar descarrega-lo
	putBeeper( );
	} // end if

}
void pickIfHave (){
if ( nextToABeeper( ) )
{
// ... de tentar carrega-lo
pickBeeper( );
} // end if
}
void pickAllIfHave (){
while ( nextToABeeper( ) )
{
// ... de tentar carrega-lo
pickBeeper( );
} // end if
}

void goToWall ()//andar até esbarrar em uma parede
{bool Res = frontIsClear();while(Res){move();Res = frontIsClear();}}

void followLeftWall(int X)//X= vezes que vai fazer
{	int x, y;
	while(X>0)
	{
		X--;
		if(leftIsClear( ))
		{turnLeft();move();}
		else
		{
			if(frontIsClear())
			{move();}
			else
			{turnRight();}
		}
		if(nextToABeeper( ))
		{while ( nextToABeeper( ))
			{
			pickBeeper( );
			}
		}
	}
}