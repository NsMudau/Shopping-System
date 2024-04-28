//---------------------------------------------------------------------------

#ifndef shopping_UH
#define shopping_UH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include "ManSummary_U.h"
//---------------------------------------------------------------------------
class Tfrmshopping : public TForm
{
__published:	// IDE-managed Components
	TListBox *lstitems;
	TButton *btnload;
	TLabel *Label1;
	TPanel *pnlscan;
	TListBox *lstcart;
	TLabel *Label2;
	TButton *btnscan;
	TLabel *lbltotal;
	TLabel *lbltotalitems;
	TButton *btnpay;
	TLabel *lblchange;
	TLabel *lblmessage;
	TButton *btnmanage;
	TStatusBar *stbinfo;
	TButton *btnsearch;
	TLabel *lblsearch;
	TEdit *edtsearch;
	TRadioGroup *rdgPaymentMethod;
	TButton *btnremove;
	void __fastcall btnloadClick(TObject *Sender);
	void __fastcall btnscanClick(TObject *Sender);
	void __fastcall btnpayClick(TObject *Sender);
	void __fastcall btnmanageClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnsearchClick(TObject *Sender);
	void __fastcall btnremoveClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tfrmshopping(TComponent* Owner);

     AnsiString ExtractFieldNoFrom(int,AnsiString,char);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrmshopping *frmshopping;
//---------------------------------------------------------------------------
#endif
