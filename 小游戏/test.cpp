#include <iostream>  
#include <conio.h>  
#include <windows.h>  
#include <time.h> 
#include <stdlib.h>
using namespace std;

#define H 24                     //height
#define W 36					 //weight
char game[H][W];				 //ȫ������
char symbol[4]={'#','*','$','@'};//�߽磬����ʳ���ͷ
enum direction {left, up, right, down}; //����  

//�Զ��庯�����ڹ�궨λ
void gotoxy(unsigned char x, unsigned char y)
{
    COORD cor;
    HANDLE hout;
    cor.X = 2*x;
    cor.Y = y+1;
    hout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleCursorPosition(hout, cor);          //�ҵ���ǰ��Ĺ��
	CONSOLE_CURSOR_INFO cursor_info={1,0}; 
	SetConsoleCursorInfo(hout, &cursor_info);     //�������
}

//ȫ�ֵ�ͼ
class globalmap{
public:
	globalmap();
	void display();
};
globalmap::globalmap(){
	for(int i=0; i < H; ++i){
            for(int j=0; j<W; ++j){  
                if(i==0 || i==H-1 || j==0 || j==W-1)  
                    game[i][j]=symbol[0];  
                else  
                    game[i][j]=' ';  
            }  
	}
}
void globalmap::display(){
	for(int i=0; i < H; ++i){
        for(int j=0; j<W; ++j)
            cout<<game[i][j]<<' '; 
		cout<<endl;
	}
	gotoxy(W+4,H/2-1);
	cout<<"Your socre is:0";
	gotoxy(W+4,H/2);
	cout<<"author:czq";
}

//�ߵĽڵ�ǰָ��βָ��
class SnakeNode{
public:  
    SnakeNode *prior, *next;  
    int x,y;  
    SnakeNode(){}  
    SnakeNode(int a, int b): x(a), y(b), prior(NULL),next(NULL){  
        game[x][y] = symbol[1];  
    }
};

//ʳ����
class Food{
private:
	int x,y;
public:
	int get_x(){return x;}
	int get_y(){return y;}
	void produce();
}food;
//ʳ������
void Food::produce(){
	int a,b;//h,w
	srand((unsigned)time(NULL)); 
	a=rand()%(W-2)+1;
	b=rand()%(H-2)+1;
	while(game[a][b]!=' '){
		a=rand()%(H-2)+1;
		b=rand()%(W-2)+1;
	}
    x=a;                        //�Ѳ�����ʳ�������¼����
	y=b;
	game[a][b]=symbol[2];      //�ڵ�ͼ�ϰ�ʳ����
}

//����
class Snake{
private:
	int score;
	direction dir;
	SnakeNode *head,*tail;
public:
	Snake():score(0),dir(::right){		
		head=new SnakeNode(4,5);
		game[4][5]=symbol[3];        //snake head
        tail=new SnakeNode(4,4);  
		game[4][4]=symbol[1]; 
		head->next = tail;  
        head->prior= tail;  
        tail->next = head;  
        tail->prior = head; 
		food.produce();   
	}
	int get_score(){return score;}
	direction get_dir(){return dir;}
	void move();
	void add_node(int a,int b);
	void delete_node();    //��β��ɾ���ڵ�
    bool change_dir(direction d);     
};
bool Snake::change_dir(direction d){
	if((dir%2)!=(d%2)){
		dir=d;
		return true;
	}
	return false;
}
void Snake::add_node(int a,int b){
	SnakeNode *p=new SnakeNode(a,b);
	p->next=head;
	head->prior=p;
	head=p;
	head->prior=tail;
	tail->next=head;
}
void Snake::delete_node(){
	head->prior=tail->prior;
	tail=tail->prior;
	tail->next=head;
}
void Snake::move(){
	int a=head->x;     //h
	int b=head->y;;    //w

	switch(dir){
	case ::left: --b; break;  
    case ::up:  --a; break;  
    case ::right: ++b; break;  
    case ::down: ++a; break;  
	}
	//�ж��Ƿ�ײǽ����ײ���Լ�
	if(a==0 || a==H-1 || b==0 || b==W-1 || game[a][b]==symbol[1]){
		gotoxy(W/2-2,H/2);
		cout<<"Game Over!"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		exit(0);
	}
	//�ж��Ƿ�Ե�ʳ��
	if(a==food.get_x() && b==food.get_y()){
		score++;
		gotoxy(W+11,H/2-1);
		cout<<this->get_score()<<endl;             //��ʾ����

        game[a][b]=' ';  
        food.produce();							   //��������ʳ��  
		gotoxy(food.get_y(),food.get_x());		   //�ҵ�ʳ��λ�ã���궨λ����ӡ
		cout<<game[food.get_x()][food.get_y()];

		game[head->x][head->y]=symbol[1];          //��game[head->x][head->y]��Ϊ����
		game[a][b]=symbol[3];					   //��game[a,b]��Ϊ��ͷ
		gotoxy(head->y,head->x);                   //�����ת��game[head->x][head->y]����ӡ����
		cout<<game[head->x][head->y];
		gotoxy(b,a);
		cout<<game[a][b];
		this->add_node(a,b);					   //��ӽڵ�
	}
	else{
		game[head->x][head->y]=symbol[1];          //��game[head->x][head->y]��Ϊ����
		game[a][b]=symbol[3];					   //��game[a,b]��Ϊ��ͷ
		gotoxy(head->y,head->x);                   //�����ת��game[head->x][head->y]����ӡ����
		cout<<game[head->x][head->y];
		gotoxy(b,a);
		cout<<game[a][b];
		this->add_node(a,b);					   //��ӽڵ�

		game[tail->x][tail->y]=' ';			       //����β��Ϊ��
		gotoxy(tail->y,tail->x);				   //�����ת
		cout<<game[tail->x][tail->y];
		this->delete_node();					   //ɾ���ڵ�
	}
}	

int main(){
	globalmap map;								   //��ʼ��map,snake
	Snake snake;
	cout << "Press the direction key to start game!" << endl;  
	map.display();									

	int ch;
	bool flag=false;
	ch = getch();								   //��ȡ������
	while(true){
		while(ch != 0xE0) ch = getch();  
        ch = getch(); 
		switch(ch){  
			case 72: flag =snake.change_dir(::up); break;  
            case 75 : flag =snake.change_dir(::left); break;  
            case 80 : flag =snake.change_dir(::down); break;  
            case 77 : flag =snake.change_dir(::right); break;  
        }
		while(!_kbhit() || flag){  
			flag = false;  
			snake.move();  
			Sleep(200); //�����ٶ� 
		} 
	}
	return 1;
}
