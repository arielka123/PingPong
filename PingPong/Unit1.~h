//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TImage *pilka;
        TTimer *pilka_Timer1;
        TImage *paletka2;
        TTimer *paletka1_gora;
        TTimer *paletka1_dol;
        TTimer *paletka2_dol;
        TTimer *paletka2_gora;
        TButton *button_nowaGra;
        TButton *button_nastepnaTura;
        TLabel *Label1;
        TLabel *punkty;
        TLabel *Label2;
        TLabel *Label_graczPrawy;
        TLabel *Label_graczLewy;
        TImage *paletka1;
        TImage *fire_lewy;
        TImage *fire_prawy;
        TImage *wygral1;
        TImage *wygral2;
        void __fastcall pilka_Timer1Timer(TObject *Sender);
        void __fastcall paletka1_goraTimer(TObject *Sender);
        void __fastcall paletka1_dolTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall paletka2_goraTimer(TObject *Sender);
        void __fastcall paletka2_dolTimer(TObject *Sender);
        void __fastcall button_nowaGraClick(TObject *Sender);
        void __fastcall button_nastepnaTuraClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 