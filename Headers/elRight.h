#pragma once
#include "form.h"
#include "piece.h"
#include "doubleLinkedList.h"



class ElRight : public Form{
    public:
    const string NAME = "ElRight";
    const int MAX_COLUMN = 8;
    
ElRight(int x) : Form(){
    color = 8;
    while (x > MAX_COLUMN)
    {
        x--;
    }
    pieces.Add(new Piece(x, -2, this));
    pieces.Add(new Piece(x, -1, this, true));
    pieces.Add(new Piece(x, 0, this));
    pieces.Add(new Piece(1 + x, 0, this));
};

ElRight(int x, int y): Form(){
    color = 14;
    pieces.Add(new Piece(x, y - 1, this));
    pieces.Add(new Piece(x, y, this, true));
    pieces.Add(new Piece(x, y + 1, this));
    pieces.Add(new Piece(1 + x, 2 + y, this));
};

void RotateForm() override{
    orientation++;
    if(orientation > 3){
        orientation = 0;
    }
    
    Piece *mainPiece = pieces.Get(1);  
    switch (orientation)
    {
    case 0:
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y - 1);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y + 1);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x + 1, mainPiece->vector2d->y + 1);
        break;
    case 1:
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x - 1, mainPiece->vector2d->y);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x + 1, mainPiece->vector2d->y);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x + 1, mainPiece->vector2d->y - 1);
        break;
    case 2:
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y + 1);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y - 1);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x - 1, mainPiece->vector2d->y - 1);
        break;
    case 3:
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x + 1, mainPiece->vector2d->y);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x - 1, mainPiece->vector2d->y);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x - 1, mainPiece->vector2d->y + 1);
        break;
    }
}

};