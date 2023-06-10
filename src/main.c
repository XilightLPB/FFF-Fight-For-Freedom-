#include <stdio.h>

//Sorry for the french comments, I'm too lazy to translate them:

//L'idée serait de crée un jeu basique qui contiendrait une Liste de bâtiments craftables qui rapporteraient passivement certaines ressources, de devoir miner les autres
//Pour cela il faudra crée une liste dynamique d'unités et de Cités
//Les ressources seront générée procéduralement sur une map dont on a définit la taille, il faudra ensuite placer les deux joueurs plus ou moins aléatoirement sur la carte
//Gérer le fait que les unités s'arrêtent sur le bois et la pierre
//Clear les alentours du spawn des joueurs (genre 5 cases autours)
//Print la matrice qui sert de map
//Ajouter une interface graphique (on se battra avec des 5 x 5 pixels)
//Ajouter un brouillard de guerre pour chaque joueurs (chaque unités ou bâtiments vois 2 cases autours de lui sauf les tours qui voient 5 cases autours et qui attaquent à partir de 4 cases)
//Définir des unités qui se battent à distances et d'autres au corps à corps



struct Player{
    int Score;
    struct UList* Units;
    struct BList* PBuildings;
    unsigned int Gold;
    unsigned int Wood;
    unsigned int Stone;
    unsigned int NumberUnit;
    unsigned int NumberToPlay;


};

struct UList{
    struct Unit* U;
    struct ULis* Next;
};

struct BList{
    struct Building* B;
    struct BList* Next;
};

struct Unit{
    unsigned int HP;
    unsigned int MaxHP;
    unsigned int Damages;
    unsigned int Range;
    unsigned int Speed;
    unsigned int coordx;
    unsigned int coordy;
    unsigned int Vision;
};

struct Building{
    struct Player* Owner;
    unsigned int HP;
    unsigned int MaxHP;
    unsigned int Level;
    unsigned int coordx;
    unsigned int coordy;


};

struct Map{
    unsigned int DimX;
    unsigned int DimY;
    char** Map;


};


void main(){
    printf("Hello world, at least it compiled\n");

    struct Map* M = (struct Map*) InitMap(10, 10);
    PrintMap(M);





}


//Initialise the map with 0 everywhere
struct Map* InitMap(unsigned int DimX,unsigned int DimY){
    struct Map* M;
    M = malloc(sizeof(struct Map));
    M->DimX = DimX;
    M->DimY = DimY;
    M->Map = malloc(sizeof(char*)*DimX);
    for(int i = 0; i < DimX; i++){
        M->Map[i] = malloc(sizeof(char)*DimY);
        for(int j = 0; j < DimY; j++){
            M->Map[i][j] = 0;
        }
    }
    return M;


}

void PrintMap(struct Map* M){
    for(int i = 0; i < M->DimX; i++){
        for(int j = 0; j < M->DimY; j++){
            printf("%c", M->Map[i][j]);
        }
        printf("\n");
    }
}
