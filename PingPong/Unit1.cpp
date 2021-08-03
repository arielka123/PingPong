//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x=-8, y = -6;
int ile=0;         //liczy odbicia
int pkt_1=0, pkt_2 =0;            //liczy pkt poszczegolnych graczy
int interval;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        AnsiString  strPowitanie = "Witaj w grze PingPong!";
        AnsiString  strx = "Lewy gracz steruje paletkπ wciskajπc klawisze A oraz Z.";
        AnsiString  stry = "Prawy gracz steruje wciskajπc strza≥ki gÛra i dÛ≥.";
        AnsiString strz ="Mi≥ej zabawy!";
        ShowMessage(strPowitanie + "\n"+ strx +"\n" +   stry +"\n"+"\n"+strz);  
}
//---------------------------------------------------------------------------

void koniecTury ()
{
    if(pkt_1>pkt_2)
    {
    Form1->wygral1->Visible=true;
    }
    else if (pkt_2>pkt_1)
    {Form1->wygral2->Visible=true;}


    Form1->Label1->Caption="GRASZ W PINGPONG";
    Form1->Label1->Visible=true;

    Form1->paletka1->Visible=false;
    Form1->paletka2->Visible=false;
    Form1->pilka->Visible=false;
    Form1->punkty->Caption = IntToStr(pkt_1) +" : " +IntToStr(pkt_2);
    Form1->Label2->Caption = "Ilosc odbic: "+IntToStr(ile);
    Form1->punkty->Visible = true;
    Form1->Label2->Visible = true;
    Form1->button_nowaGra->Visible=true;
    Form1->button_nastepnaTura->Visible=true;
}

void parametry_start ()
{
        Form1->wygral1->Visible=false;
        Form1->wygral2->Visible=false;
        Form1->fire_prawy->Visible=false;
        Form1->fire_lewy->Visible=false;
        Form1->Label_graczLewy->Visible=false;
        Form1->Label_graczPrawy->Visible=false;
        Form1->Label1->Visible =false;
        Form1->Label2->Visible =false;
        Form1->punkty->Visible =false;
        Form1->button_nastepnaTura->Visible =false;
        Form1->button_nowaGra->Visible =false;

        Form1->paletka1->Left = 80;
        Form1->paletka1->Top = 144;
        Form1->paletka2->Left  = 648;
        Form1->paletka2->Top=144;
        Form1->paletka1->Visible =true;
        Form1->paletka2->Visible=true;
        
        Form1->pilka_Timer1->Interval= 25;
        Form1->pilka->Left=350;
        Form1->pilka->Top =10;
        Form1->pilka_Timer1->Enabled=true;
        Form1->pilka->Visible=true;
}

void __fastcall TForm1::pilka_Timer1Timer(TObject *Sender)
{
     pilka->Left +=x;         //odl pilki od lewej krawedzi
     pilka->Top +=y;

     //odbij od gÛrnwj
     if(pilka->Top -5<= tlo->Top) y=-y;

     //odbij od dolnej
     if (pilka->Top + pilka->Height >= tlo->Top + tlo->Height -5) y=-y;

     // od lewej sciany;
     if(pilka->Left -5<= tlo->Left) pilka->Visible =false;

     // od prawej
     if(pilka->Left +pilka->Width +5 >= tlo->Width ) pilka->Visible =false;

       //skucha    albo odbij paletkπ

     if(pilka->Left  < paletka1->Left + paletka1->Width  - 15)
                 //skucha
       {
                 pilka_Timer1->Enabled = false;
                 pilka->Visible =false;
                 ++pkt_2 ;
                 fire_prawy->Visible=true;
                 Label_graczPrawy->Visible=true;
                 koniecTury();
       }
      else if  (pilka->Left + pilka->Width > paletka2->Left + 15 )
      {
               pilka_Timer1->Enabled = false;
               pilka->Visible =false;
               ++ pkt_1;
               fire_lewy->Visible=true;
               Label_graczLewy->Visible=true;
               koniecTury();
      }

     else if(pilka->Left + pilka->Width  >= paletka2->Left -5  &&
        pilka->Top +  pilka->Height  >= paletka2->Top - pilka->Height/2 -5 &&
        pilka->Top  <= paletka2->Top + paletka2->Height + pilka->Height/2 +5)

        {
                 ++ ile;
                x=-x;
                 if ((pilka->Top  >=  paletka1->Top +paletka1->Height/2 -30 &&
                  pilka->Top <= paletka1->Top +paletka1->Height/2 +30) ||
                  (pilka->Top +pilka->Height >=  paletka1->Top +paletka1->Height/2 -30 &&
                  pilka->Top +pilka->Height<= paletka1->Top +paletka1->Height/2 +30))
                         {

                               // interval=  (pilka_Timer1->Interval) -10;
                                pilka_Timer1->Interval= 15;

                         }

        }

     else  if( pilka->Left <= paletka1->Left + paletka1->Width +5 &&
       pilka->Top + pilka->Height  >= paletka1->Top - pilka->Height/2 -5&&
       pilka->Top  <= paletka1->Top + paletka1->Height + pilka->Height/2 +5)
       {

       
       ++ ile;
       x=-x;
                  if ((pilka->Top  >=  paletka1->Top +paletka1->Height/2 -30 &&
                  pilka->Top <= paletka1->Top +paletka1->Height/2 +30) ||
                  (pilka->Top +pilka->Height >=  paletka1->Top +paletka1->Height/2 -30 &&
                  pilka->Top +pilka->Height<= paletka1->Top +paletka1->Height/2 +30))
                         {
                        //interval=  (pilka_Timer1->Interval) -10;
                        pilka_Timer1->Interval= 15;

                         }

       }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::paletka1_goraTimer(TObject *Sender)
{
   if (paletka1->Top > 10) paletka1->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paletka1_dolTimer(TObject *Sender)
{
    if (paletka1->Top + paletka1->Height < tlo->Height - 10) paletka1->Top +=10;
}
//---------------------------------------------------------------------------
  

void __fastcall TForm1::paletka2_goraTimer(TObject *Sender)
{
        if (paletka2->Top > 10) paletka2->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paletka2_dolTimer(TObject *Sender)
{
        if (paletka2->Top + paletka2->Height < tlo->Height - 10) paletka2->Top +=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key ==0x41) paletka1_gora->Enabled=true;
    if(Key ==0x5A) paletka1_dol->Enabled=true;

    if(Key ==VK_UP) paletka2_gora->Enabled=true;
    if(Key ==VK_DOWN) paletka2_dol->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key ==0x41) paletka1_gora->Enabled=false;    //A
        if(Key == 0x5A) paletka1_dol->Enabled=false;    //Z

        if(Key == VK_UP) paletka2_gora->Enabled=false;
        if(Key == VK_DOWN) paletka2_dol->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::button_nowaGraClick(TObject *Sender)
{
     if(ile>0)
     {
        if(Application->MessageBox("Czy na pewno chesz rozpoczac nowa gre?", "Potwierdü",
        MB_YESNOCANCEL | MB_ICONQUESTION)==IDYES)         //   | MB_ICONQUESTION
        {
        parametry_start();
        ile=0;
        pkt_1=0;
        pkt_2 =0;
        }
      }
      else
      {
      parametry_start();
      ile=0;
      pkt_1=0;
      pkt_2 =0;
      }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::button_nastepnaTuraClick(TObject *Sender)
{
       parametry_start();
}
//---------------------------------------------------------------------------

