#include <iostream>

using namespace std;

void display(int **board, int size){
  int help;

  cout<<endl;
  cout<<"   ";
  for(int i=1; i<size+1; i++)cout<<i<<" ";
  cout<<endl<<endl;
  help=0;
	for(int i=0; i<size; i++){
      help++;
      cout<<help<<"  ";
			for(int j=0; j<size; j++)std::cout<<board[i][j]<<" ";
			std::cout<<std::endl;
	}
}

bool playerwin(int **board, int size){
  int position=0;

  for(int i=0; i<size; i++){
    position=0;
    while(board[i][position]==1){
      position ++;
      if(position==size) return true;
    }
  }
  for(int i=0; i<size; i++){
    position=0;
    while(board[position][i]==1){
      position ++;
      if(position==size) return true;
    }
  }
  position=0;
  while(board[position][position]==1){
    position ++;
    if(position==size) return true;
  }
  position=0;
  while(board[size-1-position][position]==1){
    position ++;
    if(position==size) return true;
  }
  return false;
}


bool computerwin(int **board, int size){
  int position=0;

  for(int i=0; i<size; i++){
    position=0;
    while(board[i][position]==2){
      position ++;
      if(position==size) return true;
    }
  }
  for(int i=0; i<size; i++){
    position=0;
    while(board[position][i]==2){
      position ++;
      if(position==size) return true;
    }
  }
  position=0;
  while(board[position][position]==2){
    position ++;
    if(position==size) return true;
  }
  position=0;
  while(board[size-1-position][position]==2){
    position ++;
    if(position==size) return true;
  }
  return false;
}

void swap(int tab[22][2], int val1, int val2){
  int temp[2];

  temp[0]=tab[val1][0];
  temp[1]=tab[val1][1];

  tab[val1][0]=tab[val2][0];
  tab[val1][1]=tab[val2][1];

  tab[val2][0]=temp[0];
  tab[val2][1]=temp[1];

}

void sorttab(int tab[22][2], int size){
  int small=0, pointer=0, help=0;

  for(int i=0; i<size*2 + 2; i++){
    small=tab[i][1];
    help=0;
    for(int j=i; j<size*2 + 2; j++){
      if(tab[j][1]>small){
        small=tab[j][1];
        pointer=j;
        help=1;
      }
    }
    if(help==1){
      swap(tab, i, pointer);
    }
  }
}

void    computermove(int playertab[22][2], int computertab[22][2], int  **board, int size,int change){
int place=0, pointer=0;


//jezeli jest pierwszy  to zajmuje najpierw katy jezeli drugi to srodek
if(change==1){
  if(board[size/2][size/2]==0){
    board[size/2][size/2]=2;
    return;
  }
  change=2;
}

//najpierw sprawdza czy moze wygrac w tym ruchu jezeli tak to wygrywa

for(int i=0; i<2*size+2; i++){
  if(computertab[i][1]==size-1){
    if(computertab[i][0]>=0 && computertab[i][0]<size){
      for(int j=0; j<size; j++){
        if(board[computertab[i][0]][j]==0){
          cout<<"wygrywam1"<<computertab[i][0]<<"  "<<j<<endl;
          board[computertab[i][0]][j]=2;
          return;
        }
      }
    }else
    if(computertab[i][0]>=size && computertab[i][0]<2*size){
      for(int j=0; j<size; j++){
        if(board[j][computertab[i][0] - size]==0){
          cout<<"wygrywam2"<<j<<"  "<<computertab[i][0]-size<<endl;
          board[j][computertab[i][0]-size]=2;
          return;
        }
      }
    }else
    if(computertab[i][0]==2*size){
      for(int j=0; j<size; j++){
        if(board[j][j]==0){
          cout<<"wygrywam3"<<j<<"  "<<j<<endl;
          board[j][j]=2;
          return;
        }
      }
    }else
    if(computertab[i][0]==2*size+1){
      for(int j=0; j<size; j++){
        if(board[size - j - 1][j]==0){
          cout<<"wygrywam4"<<size-j-1<<"  "<<j<<endl;
          board[size - j - 1][j]=2;
          return;
        }
      }
    }
  }
}





//szukanie czy gracz moze wygrac w nastepnym ruchu jezeli tak to blokuje
    for(int i=0; i<2*size+2; i++){
      if(playertab[i][1]==size-1){
        if(playertab[i][0]>=0 && playertab[i][0]<size){
          for(int j=0; j<size; j++){
            if(board[playertab[i][0]][j]==0){
              cout<<"blokuje"<<endl;
              board[playertab[i][0]][j]=2;
              return;
            }
          }
        }else
        if(playertab[i][0]>=size && playertab[i][0]<2*size){
          for(int j=0; j<size; j++){
            if(board[j][playertab[i][0] - size]==0){
              cout<<"blokuje"<<endl;
              board[j][playertab[i][0]-size]=2;
              return;
            }
          }
        }else
        if(playertab[i][0]==2*size){
          for(int j=0; j<size; j++){
            if(board[j][j]==0){
              cout<<"blokuje"<<endl;
              board[j][j]=2;
              return;
            }
          }
        }else
        if(playertab[i][0]==2*size+1){
          for(int j=0; j<size; j++){
            if(board[size - j - 1][j]==0){
             cout<<"blokuje"<<endl;
              board[size - j - 1][j]=2;
              return;
            }
          }
        }
      }
    }

    //jezeli gracz nie wygrywa w nastepnym
    //ruchu to komputer stawia swoj pionek
    if(change==0){
        if(board[0][0]==0){
         cout<<"0"<<"  "<<"0"<<endl;
          board[0][0]=2;
          return;
        }else
        if(board[size-1][size-1]==0){
          cout<<"tutaj chyba blad 0"<<"  "<<size-1<<endl;
          board[size-1][size-1]=2;
          return;
        }else
        if(board[size - 1][0]==0){
          cout<<size-1<<"  "<<"0"<<endl;
          board[size - 1][0]=2;
          return;
        }else
        if(board[0][size - 1]==0){
          cout<<size-1<<"  "<<size-1<<endl;
          board[0][size - 1]=2;
          return;
        }
      }  //jezeli wszystkie katy ss zajete to stawia tam gdzie jest najwiecej pionkow i mozliwosc wygranej

      for(int i=0; i<2*size+2; i++){
          if(computertab[i][0]>=0 && computertab[i][0]<size){
            place=0;
            for(int j=0; j<size; j++){
              if(board[computertab[i][0]][j]==1)place=1;
              if(board[computertab[i][0]][j]==0)pointer=j;
            }
            if(place==0){
              cout<<"wstawil1"<<computertab[i][0]<<"  "<<pointer<<endl;
              board[computertab[i][0]][pointer]=2;
              return;
            }
          }else
          if(computertab[i][0]>=size && computertab[i][0]<2*size){
            place=0;
            for(int j=0; j<size; j++){
              if(board[j][computertab[i][0]-size]==1)place=1;
              if(board[j][computertab[i][0]-size]==0)pointer=j;
            }
            if(place==0){
             cout<<"wstawil2"<<pointer<<"  "<<computertab[i][0]-size<<endl;
              board[pointer][computertab[i][0]-size]=2;
              return;
            }
          }else
          if(computertab[i][0]==2*size){
            place=0;
            for(int j=0; j<size; j++){
              if(board[j][j]==1)place=1;
              if(board[j][j]==0)pointer=j;
              }
              if(place==0){
                cout<<"wstawil3"<<pointer<<"  "<<pointer<<endl;
                board[pointer][pointer]=2;
                return;
              }
          }
          else
          if(computertab[i][0]==2*size+1){
            //cout<<"whodzi tu"<<endl;
            place=0;
            for(int j=0; j<size; j++){
              if(board[size - j - 1][j]==1)place=1;
              if(board[size - j - 1][j]==0)pointer=j;
              }
              if(place==0){
                cout<<"wstawil4"<<size - pointer - 1<<"  "<<pointer<<endl;
                board[size - pointer - 1][pointer]=2;
                return;
              }
            }
        }    //jezeli nie ma mozliwosci wygracto blokuje gracza   w miejscu gdzie ma najwiecej pionkow

        for(int i=0; i<2*size+2; i++){
            if(playertab[i][0]>=0 && playertab[i][0]<size){
              place=0;
              for(int j=0; j<size; j++){
                if(board[playertab[i][0]][j]==2)place=1;
                if(board[playertab[i][0]][j]==0)pointer=j;
              }
              if(place==0){
                cout<<"inne1"<<playertab[i][0]<<"  "<<pointer<<endl;
                board[playertab[i][0]][pointer]=2;
                return;
              }
            }else
            if(playertab[i][0]>=size && playertab[i][0]<2*size){
              place=0;
              for(int j=0; j<size; j++){
                if(board[j][playertab[i][0]-size]==2)place=1;
                if(board[j][playertab[i][0]-size]==0)pointer=j;
              }
              if(place==0){
               cout<<"inne2"<<pointer<<"  "<<playertab[i][0]-size<<endl;
                board[pointer][playertab[i][0]-size]=2;
                return;
              }
            }else
            if(playertab[i][0]==2*size){
              place=0;
              for(int j=0; j<size; j++){
                if(board[j][j]==2)place=1;
                if(board[j][j]==0)pointer=j;
                }
                if(place==0){
                  cout<<"inne3"<<pointer<<"  "<<pointer<<endl;
                  board[pointer][pointer]=2;
                  return;
                }
            }
            else
            if(playertab[i][0]==2*size+1){
              //cout<<"whodzi tu"<<endl;
              place=0;
              for(int j=0; j<size; j++){
                if(board[size - j - 1][j]==2)place=1;
                if(board[size - j - 1][j]==0)pointer=j;
                }
                if(place==0){
                  cout<<"inne4"<<size - pointer - 1<<"  "<<pointer<<endl;
                  board[size - pointer - 1][pointer]=2;
                  return;
                }
              }
          }
// a tu juz wstawi zeby sobie tak powstawiac
for(int i=0; i<2*size+2; i++){
    if(playertab[i][0]>=0 && playertab[i][0]<size){
      for(int j=0; j<size; j++){
        if(board[playertab[i][0]][j]==0){
          pointer=j;
          place=0;
          }
      }
      if(place==0){
        cout<<"inne1"<<playertab[i][0]<<"  "<<pointer<<endl;
        board[playertab[i][0]][pointer]=2;
        return;
      }
    }else
    if(playertab[i][0]>=size && playertab[i][0]<2*size){
      for(int j=0; j<size; j++){
        if(board[j][playertab[i][0]-size]==0){
          pointer=j;
          place=0;
          }
      }
      if(place==0){
       cout<<"inne2"<<pointer<<"  "<<playertab[i][0]-size<<endl;
        board[pointer][playertab[i][0]-size]=2;
        return;
      }
    }else
    if(playertab[i][0]==2*size){
      for(int j=0; j<size; j++){
        if(board[j][j]==0){
          pointer=j;
          place=0;
          }
        }
        if(place==0){
          cout<<"inne3"<<pointer<<"  "<<pointer<<endl;
          board[pointer][pointer]=2;
          return;
        }
    }
    else
    if(playertab[i][0]==2*size+1){
      //cout<<"whodzi tu"<<endl;
      for(int j=0; j<size; j++){
        if(board[size - j - 1][j]==0){
          pointer=j;
          place=0;
          }
        }
        if(place==0){
          cout<<"inne4"<<size - pointer - 1<<"  "<<pointer<<endl;
          board[size - pointer - 1][pointer]=2;
          return;
        }
      }
  }
        cout<<"blad nic nie wstawiono"<<endl;
      }



int main(){
  int size=0, x=0, y=0, turn=0,  ctrplayer=0, ctrcomputer=0, first=0, change=0;
  int playertab[22][2], computertab[22][2];
  cout<<"podaj rozmiar planszy(dozwolone rozmiary od 3 do 10)"<<endl;
  cin>>size;
  while(size<3 || size>10){
    cout<<"podano zly rozmiar planszy podaj jeszcze raz"<<endl;
    cin>>size;
  }
  cout<<"wybierz kto ma aczac 1-gracz, 0-komputer"<<endl;
  cin>>first;
  while(first!=0 && first!=1){
    cout<<"podano zla wartosc podaj jeszcze raz"<<endl;
    cin>>first;
  }
  change=first;
  //przygotowanie planszy
  int **board = new int*[size];
  for(int i=0; i<size; i++)
		board[i]= new int[size];
    for(int i=0; i<size; i++)
  	 for(int j=0; j<size; j++) board[i][j]=0;
  display(board, size);
  turn=0;
  //czesc wlasciwa
  while(true){
    //kolejka gracza
    if(first==1){
      cout<<"podaj wlspolrzedne umieszczenia symbolu [wiersz] [kolumna]"<<endl;
      x=0;
      y=0;
      cin>>x>>y;
      while(x<1 || x>size || y<1 || y>size || board[x-1][y-1]==1 || board[x-1][y-1]==2){
        cout<<"podano zle wartosci wspolrzednych podaj jeszcze  raz"<<endl;
        cin>>x>>y;
      }
      board[x-1][y-1]=1;
      if(playerwin(board, size)){
        display(board, size);
        cout<<"gracz wygral"<<endl;
        return 0;
      }
      turn++;
      if(turn==size*size){
        display(board, size);
        cout<<"remis"<<endl;
        return 0;
      }
    }else     first=1;
  //kolejka komputera

  //tworzenie listy gdzie gracz ma najwiecej pionkow

  for(int i=0; i<size; i++){
    ctrplayer=0;
    for(int j=0; j<size; j++){
      if(board[i][j]==1)  ctrplayer++;
    }
    playertab[i][0]=i;
    playertab[i][1]=ctrplayer;
  }
  for(int i=0; i<size; i++){
    ctrplayer=0;
    for(int j=0; j<size; j++){
      if(board[j][i]==1)  ctrplayer++;
    }
    playertab[size+i][0]=size+i;
    playertab[size+i][1]=ctrplayer;
  }

  ctrplayer=0;
  for(int i=0; i<size; i++){
    if(board[i][i]==1)  ctrplayer++;
    }
    playertab[2*size][0]=2*size;
    playertab[2*size][1]=ctrplayer;

  ctrplayer=0;
  for(int i=0; i<size; i++){
    if(board[size - i - 1][i]==1)  ctrplayer++;
    }
    playertab[2*size+1][0]=2*size+1;
    playertab[2*size+1][1]=ctrplayer;
//sortowanie tablicy z pionkami gracza
    sorttab(playertab, size);


//szukanie gdzie komputer ma najwiecej poionkow
for(int i=0; i<size; i++){
  ctrcomputer=0;
  for(int j=0; j<size; j++){
    if(board[i][j]==2)  ctrcomputer++;
  }
  computertab[i][0]=i;
  computertab[i][1]=ctrcomputer;
}
for(int i=0; i<size; i++){
  ctrcomputer=0;
  for(int j=0; j<size; j++){
    if(board[j][i]==2)  ctrcomputer++;
  }
  computertab[size+i][0]=size+i;
  computertab[size+i][1]=ctrcomputer;
}

ctrcomputer=0;
for(int i=0; i<size; i++){
  if(board[i][i]==2)  ctrcomputer++;
  }
  computertab[2*size][0]=2*size;
  computertab[2*size][1]=ctrcomputer;

ctrcomputer=0;
for(int i=0; i<size; i++){
  if(board[size - i - 1][i]==2)  ctrcomputer++;
  }
  computertab[2*size+1][0]=2*size+1;
  computertab[2*size+1][1]=ctrcomputer;
// sortowanie tablicy z pionkamikomputera
    sorttab(computertab, size);
    //for(int i=0; i< 2*size+2; i++){
    // cout<<computertab[i][0]<<"  "<<computertab[i][1]<<endl;
    //}


    computermove(playertab, computertab, board, size, change);
        display(board, size);


    if(computerwin(board, size)){
      cout<<"komputer wygral"<<endl;
      return 0;
    }
    turn++;
    if(turn==size*size){
      cout<<"remis"<<endl;
      return 0;
    }

  }
}
