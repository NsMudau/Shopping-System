//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "shopping_U.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrmshopping *frmshopping;
 int total=0;

//---------------------------------------------------------------------------
__fastcall Tfrmshopping::Tfrmshopping(TComponent* Owner)
	: TForm(Owner)
{

}

void __fastcall Tfrmshopping::FormShow(TObject *Sender)
{ 																																			  //[2]

		 stbinfo->Panels->Items[0]->Text = "Today is"
+ FormatDateTime(" dddd - d - mmmm - yyyy",Now());
stbinfo->Panels->Items[1]->Text = "This application started at"
+ FormatDateTime(" hh:nn:ss",Now());


}
//--- Q 1.2 --------------------------------------------------------------------

void __fastcall Tfrmshopping::btnloadClick(TObject *Sender)
{ 																																	      //[9]
   AnsiString Ln;
	  lstitems->Items->LoadFromFile("..\\..\\Win32\\Debug\\items.txt");
	  int noItems = lstitems->Count;
for (int x = 0; x < noItems; x++)
{
Ln = lstitems->Items->Strings[x];
while (Ln.Pos("#") > 0)
Ln[Ln.Pos("#")] = '\t';
lstitems->Items->Strings[x] = Ln;
}
 pnlscan->Visible=true;

}

  ng Line=lstitems->Items->Strings[lstitems->ItemIndex];
 AnsiStrinAnsiString Tfrmshopping::ExtractFieldNoFrom(int Number, AnsiString line, char Delim)
{
line += Delim;
for (int i = 0; i < Number; i++)
{
line.Delete(1, line.AnsiPos(Delim));
}
return line.SubString(1, line.AnsiPos(Delim)-1);
}
void __fastcall Tfrmshopping::btnscanClick(TObject *Sender)
{ 																																			  //[15]
 //
 if(lstitems->ItemIndex>=0)
 {AnsiStrig capture;
 capture = ExtractFieldNoFrom(1,Line,'\t')+" "+ExtractFieldNoFrom(0,Line,'\t')
 +" "+ExtractFieldNoFrom(2,Line,'\t');
  lstcart->Items->Add(capture);
  AnsiString nr=ExtractFieldNoFrom(2,Line,'\t');
  nr.Delete(0,1);
  int num=StrToInt(nr);
  total=total+num;

  lbltotal->Caption="Total Amount:R"+IntToStr(total);
		 lbltotal->Show();
   lstcart->Items->Add(capture);

	lbltotalitems->Caption="Total items:"+IntToStr(lstcart->Items->Count);
 //lstcart->AddItem(capture);
 int quanties=StrToInt(ExtractFieldNoFrom(4,Line,'\t'));

 Line=ExtractFieldNoFrom(0,Line,'\t')+'\t'+ExtractFieldNoFrom(1,Line,'\t')
 +'\t'+ExtractFieldNoFrom(2,Line,'\t')+'\t'+ExtractFieldNoFrom(3,Line,'\t')
 +'\t'+	IntToStr(quanties-1);
   lstitems->Items->Strings[lstitems->ItemIndex]=Line;
	btnremove->Visible=true;
	btnremove->Enabled=true;
   }


   else
   {
	MessageDlg("Please select on the item you want to buy",mtInformation,TMsgDlgButtons() << mbOK, 0);
   }

}
void __fastcall Tfrmshopping::btnsearchClick(TObject *Sender)
{																																				  //8
//

for(int x=0;x<lstitems->Items->Count;x++)
{
  AnsiString nLn= lstitems->Items->Strings[x];
  if(edtsearch->Text==ExtractFieldNoFrom(3,nLn,'\t'))
  {

	 ShowMessage("Item available, see selected line ");
	  lstitems->ItemIndex=x;
  }


}

}

void __fastcall Tfrmshopping::btnremoveClick(TObject *Sender)
{ 																																			  //18
//


 if(lstcart->ItemIndex>=0)
 {
  total=total-1;         //total is a global variable

  lbltotal->Caption="Total Amount:R"+IntToStr(total);
		 lbltotal->Show();
	lbltotalitems->Caption="Total items:"+IntToStr(lstcart->Items->Count);

	 AnsiString Line=lstitems->Items->Strings[lstitems->ItemIndex];

		int qty=StrToInt(ExtractFieldNoFrom(4,Line,'\t'));
		  qty=qty+1;
	  Line=ExtractFieldNoFrom(0,Line,'\t')+'\t'+ExtractFieldNoFrom(1,Line,'\t')
 +'\t'+ExtractFieldNoFrom(2,Line,'\t')+'\t'+ExtractFieldNoFrom(3,Line,'\t')
 +'\t'+	IntToStr(qty);

   lstitems->Items->Strings[lstitems->ItemIndex]=Line;

	lstcart->DeleteSelected();
 }
 else
 {
   MessageDlg("Please select on the item you want to remove",mtInformation,TMsgDlgButtons() << mbOK, 0);
	}
   }



void __fastcall Tfrmshopping::btnpayClick(TObject *Sender)
{

  bool succesfull=false;																																				  //19
 if(lstcart->ItemIndex>=0)
 {






	if(rdgPaymentMethod->ItemIndex==0)
	{
		int change;
	 AnsiString inputbox;

	InputBox(L"Payment",L"Please enter the amount you want to pay",inputbox);
	 int cash=StrToInt(inputbox);
	 if(cash>total)
	 {
		 change=cash-total;
		 succesfull=true;
	 }
	 else if(cash=total)
	 {
	 change=0;
	  succesfull=true;
	 }
	 else if(cash<total)
	 {

	   lblmessage->Caption="“insufficient funds";

	 }

	  lblchange->Caption="ChangeR:"+IntToStr(change);



	}else if(rdgPaymentMethod->ItemIndex==1)
	{

	   lblchange->Caption="Change:R"+IntToStr(0);
	lblmessage->Caption= "Slip printed. Good bye, call again";

	  succesfull=true;
	}
else
  {
   MessageDlg("“Please select payment method..!",mtError,TMsgDlgButtons() << mbOK, 0);
  }
 }
 else
 {
   MessageDlg("There is nothing in the cart..!",mtError,TMsgDlgButtons() << mbOK, 0);
 }

 while(succesfull=true)
 {
	 AnsiString SavedData = "..\\..\\Debug\\SavedData).txt";
	 TStreamWriter *stWrite = new TStreamWriter(SavedData, false);
for (int x = 0; x < lstcart->Items->Count; x++)
{
AnsiString nLn = lstcart->Items->Strings[x];

stWrite->WriteLine(nLn);


}
  stWrite->WriteLine("total amount:"+lbltotal->Caption);
  stWrite->WriteLine("total amount:"+lbltotalitems->Caption);
  stWrite->WriteLine("*********************");
  stWrite->Close();
ShowMessage("Data saved" + SavedData + "'");

 }

}

void __fastcall Tfrmshopping::btnmanageClick(TObject *Sender)
{
 frmsummary->Show();

	AnsiString Ln,Ln2;

	  lstsummary->Items->LoadFromFile("..\\..\\Win32\\Debug\\SavedData.txt");
	  int noItems = lstsummary->Count;
	   int nor;
for (int x = 0; x < noItems; x++)
{
 nor=1;

Ln = lstsummary->Items->Strings[x];
Ln=Ln+'t/'+"x1"+'t/'+"*";

if(Ln.Pos("************")>1)
}{
  Ln="";
}
else{
	  for(int y=0;y<noItems;y++)
	  { Ln2 = lstsummary->Items->Strings[y];
		  Ln2=Ln+'t/'+"x1"+'t/'+"*";
		  if(Ln=Ln2)
		  {
		  nor++;

			int posi=Ln.Pos(ExtractFieldNoFrom(3,Ln,'\t'));
			Ln.Delete(posi,posi+1);
			Ln=Ln.Insert("x"+IntToStr(nor),posi);
			Ln=Ln.Insert("*",Ln.Pos(ExtractFieldNoFrom(4,Ln,'\t')))

		  }


	  }



}
lstsummary->Items->Strings[x] = Ln;


}









