#define SCREEN_WIDTH  128 //definice šírky displeje
#define SCREEN_HEIGHT 64  //definice výšky displeje
#define LEFT  3 //definice vstupu pro tlačítko (směr doleva)
#define RIGHT 4 //definice vstupu pro tlačítko (směr doprava) 
#define UP    5 //definice vstupu pro tlačítko (směr nahoru)
#define DOWN  6 //definice vstupu pro tlačítko (směr dolů)
#define MAGIC_CONSTANT 1337 //definice konstanty pro náhodné generování
#define STARTING_X_POS 32 //definice počáteční x-pozice hada
#define STARTING_Y_POS 32 //definice počáteční y-pozice hada
#define WINDOW_MIN_X 1 //definice nejmenší x-pozice arény
#define WINDOW_MAX_X SCREEN_WIDTH-1 //definice největší x-pozice arény
#define WINDOW_MIN_Y 1 //definice nejmenší y-pozice arény
#define WINDOW_MAX_Y SCREEN_HEIGHT-1 //definice nejmenší y-pozice arény

int x_tail; //proměnná x-pozice ocasu hada
int y_tail; //proměnná y-pozice ocasu hada
int direction; //proměnná směru
int prev_dir; //proměnná předchozího směru
int pix[SCREEN_WIDTH][SCREEN_HEIGHT]; //proměnná rozlišení obrazovky
int x_pos; //proměnná x-pozice hlavy hada
int y_pos; //proměnná x-pozice hlavy hada
int x_treat; //proměnná x-pozice jídla
int y_treat; //proměnná y-pozice jídla
int death; //proměnná kontroly úmrtí
int score; //proměnná skore
int random_var; //proměnná náhodné hodnoty

void reset(); //funkce pro prvotní spuštění a reset hry
void readButtonInput(); //funkce pro čtení tlačítek
void generateNewTreat(); //funkce pro generování jídla
void moveTailByOne(); //funkce pro pohyb hada
void gameOver(); //funkce pro vykreslení 
