//
// MainPage.xaml.cpp
// Implementacja klasy MainPage.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace Projekt_v1;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// Szablon elementu Pusta strona jest udokumentowany na stronie http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
	expression = "";
	result = "";
}

#pragma region Calculator

#pragma region Special Buttons

void Projekt_v1::MainPage::ButtonCl_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if(expression != "")
		expression.pop_back();
	if (Input->Text != "") {

		wstring buff = Input->Text->Data();
		buff.pop_back();
		Input->Text = String(buff.c_str()).ToString();
	}
}

void Projekt_v1::MainPage::ButtonClr_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression = "";
	result = "";
	answer = "";
	Input->Text = "";
	Output->Text = "";
}


void Projekt_v1::MainPage::ButtonHEX_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "0x";
	Input->Text += "0x";
}


void Projekt_v1::MainPage::ButtonOCT_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "ox";
	Input->Text += "ox";
}


void Projekt_v1::MainPage::ButtonBIN_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "bx";
	Input->Text += "bx";
}


void Projekt_v1::MainPage::ButtonAdd_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "+";
	Input->Text += "+";
}


void Projekt_v1::MainPage::ButtonSub_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "-";
	Input->Text += "-";
}


void Projekt_v1::MainPage::ButtonMult_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "*";
	Input->Text += "*";
}


void Projekt_v1::MainPage::ButtonDiv_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "/";
	Input->Text += "/";
}

void Projekt_v1::MainPage::ButtonPow_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "^";
	Input->Text += "^";
}

void Projekt_v1::MainPage::ButtonMod_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "%";
	Input->Text += "%";
}

void Projekt_v1::MainPage::ButtonLeftParan_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "(";
	Input->Text += "(";
}

void Projekt_v1::MainPage::ButtonRightParan_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += ")";
	Input->Text += ")";
}

void Projekt_v1::MainPage::ButtonAns_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += answer;
	wstring buff(answer.begin(), answer.end());
	Input->Text += String(buff.c_str()).ToString();;
}

#pragma region HEX Numbers
void Projekt_v1::MainPage::ButtonA_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "A";
	Input->Text += "A";
}

void Projekt_v1::MainPage::ButtonB_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "B";
	Input->Text += "B";
}

void Projekt_v1::MainPage::ButtonC_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "C";
	Input->Text += "C";
}

void Projekt_v1::MainPage::ButtonD_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "D";
	Input->Text += "D";
}

void Projekt_v1::MainPage::ButtonE_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "E";
	Input->Text += "E";
}

void Projekt_v1::MainPage::ButtonF_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "F";
	Input->Text += "F";
}
#pragma endregion

void Projekt_v1::MainPage::ButtonEqu_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	wstring ws(Input->Text->Data());
	string s(ws.begin(), ws.end());
	expression = s;

	p_Calc = new Calculator(expression);
	result = p_Calc->GetOutputVal();
	//result = to_string(result_f);
	answer = result;

	wstring buff(result.begin(), result.end());
	Output->Text = Input->Text + "=" + String(buff.c_str()).ToString();

	expression = "";
	result = "";
	Input->Text = "";
	
	delete p_Calc;
}


#pragma endregion


#pragma region Button Numbers

void Projekt_v1::MainPage::Button1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "1";
	Input->Text += "1";
}


void Projekt_v1::MainPage::Button2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "2";
	Input->Text += "2";
}

void Projekt_v1::MainPage::Button3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "3";
	Input->Text += "3";
}

void Projekt_v1::MainPage::Button4_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "4";
	Input->Text += "4";
}

void Projekt_v1::MainPage::Button5_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "5";
	Input->Text += "5";
}

void Projekt_v1::MainPage::Button6_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "6";
	Input->Text += "6";
}

void Projekt_v1::MainPage::Button7_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "7";
	Input->Text += "7";
}

void Projekt_v1::MainPage::Button8_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "8";
	Input->Text += "8";
}

void Projekt_v1::MainPage::Button9_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "9";
	Input->Text += "9";
}

void Projekt_v1::MainPage::Button0_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	expression += "0";
	Input->Text += "0";
}

#pragma endregion

#pragma endregion

#pragma region Converter

void Projekt_v1::MainPage::ComboBox_SelectionChanged1(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{
#pragma region Obsługa Comboboxa2
	if (comboBox1->SelectedIndex == 0 ||
		comboBox1->SelectedIndex == 1 ||
		comboBox1->SelectedIndex == 2 ||
		comboBox1->SelectedIndex == 3 ||
		comboBox1->SelectedIndex == 4 ||
		comboBox1->SelectedIndex == 5 ||
		comboBox1->SelectedIndex == 6 ||
		comboBox1->SelectedIndex == 7 ||
		comboBox1->SelectedIndex == 8) {
		AddElementsToComboBox2_Length();
	}
	else if (comboBox1->SelectedIndex == 9 ||
		comboBox1->SelectedIndex == 10 ||
		comboBox1->SelectedIndex == 11 ||
		comboBox1->SelectedIndex == 12 ||
		comboBox1->SelectedIndex == 13) {
		AddElementsToComboBox2_Weight();
	}
	else if (comboBox1->SelectedIndex == 14 ||
		comboBox1->SelectedIndex == 15 ||
		comboBox1->SelectedIndex == 16 ||
		comboBox1->SelectedIndex == 17 ||
		comboBox1->SelectedIndex == 18 ||
		comboBox1->SelectedIndex == 19) {
		AddElementsToComboBox2_Power1();
	}
	else if (comboBox1->SelectedIndex == 20 ||
		comboBox1->SelectedIndex == 21) {
		AddElementsToComboBox2_Power2();
	}
	else if (comboBox1->SelectedIndex == 22 ||
		comboBox1->SelectedIndex == 23 ||
		comboBox1->SelectedIndex == 24) {
		AddElementsToComboBox2_Temp();
	}
	else if (comboBox1->SelectedIndex == 25 ||
		comboBox1->SelectedIndex == 26 ||
		comboBox1->SelectedIndex == 27 ||
		comboBox1->SelectedIndex == 28) {
		AddElementsToComboBox2_Numb();
	}
	else {}
#pragma endregion

#pragma region Ustalenie Typu1
	if (comboBox1->SelectedIndex == 0) p_in_L=(mm);
	else if (comboBox1->SelectedIndex == 1) p_in_L=(cm);
	else if (comboBox1->SelectedIndex == 2) p_in_L=(m);
	else if (comboBox1->SelectedIndex == 3) p_in_L=(km);
	else if (comboBox1->SelectedIndex == 4) p_in_L=(uin);
	else if (comboBox1->SelectedIndex == 5) p_in_L=(in);
	else if (comboBox1->SelectedIndex == 6) p_in_L=(ft);
	else if (comboBox1->SelectedIndex == 7) p_in_L=(yd);
	else if (comboBox1->SelectedIndex == 8) p_in_L=(mi);

	else if (comboBox1->SelectedIndex == 9) p_in_W=(kg);
	else if (comboBox1->SelectedIndex == 10) p_in_W=(g);
	else if (comboBox1->SelectedIndex == 11) p_in_W=(mg);
	else if (comboBox1->SelectedIndex == 12) p_in_W=(lb);
	else if (comboBox1->SelectedIndex == 13) p_in_W=(oz);

	else if (comboBox1->SelectedIndex == 14) p_in_P=(mW);
	else if (comboBox1->SelectedIndex == 15) p_in_P=(W);
	else if (comboBox1->SelectedIndex == 16) p_in_P=(dBm);
	else if (comboBox1->SelectedIndex == 17) p_in_P=(dBW);
	else if (comboBox1->SelectedIndex == 18) p_in_P=(mV);
	else if (comboBox1->SelectedIndex == 19) p_in_P=(V);
	else if (comboBox1->SelectedIndex == 20) p_in_P=(k);
	else if (comboBox1->SelectedIndex == 21) p_in_P=(dB);

	else if (comboBox1->SelectedIndex == 22) p_in_T=(F);
	else if (comboBox1->SelectedIndex == 23) p_in_T=(C);
	else if (comboBox1->SelectedIndex == 24) p_in_T=(K);

	else if (comboBox1->SelectedIndex == 25) p_in_N=(BIN);
	else if (comboBox1->SelectedIndex == 26) p_in_N=(OCT);
	else if (comboBox1->SelectedIndex == 27) p_in_N=(HEX);
	else if (comboBox1->SelectedIndex == 28) p_in_N=(DEC);

	else {}
#pragma endregion
}

#pragma region Ustalenie Typu 2
void Projekt_v1::MainPage::ComboBox_SelectionChanged2(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{
	ComboBox2_Run();
}

void Projekt_v1::MainPage::ComboBox2_Run() {
	switch (comboBox1->SelectedIndex) {
	case 0: case 1: case 2: case 3: case 4:	case 5: case 6:	case 7:	case 8:
		switch (comboBox2->SelectedIndex) {
		case 0: p_out_L = (mm); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_L, p_out_L); break;
		case 1: p_out_L = (cm); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_L, p_out_L); break;
		case 2: p_out_L = (m);delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_L, p_out_L); break;
		case 3: p_out_L = (km);delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_L, p_out_L); break;
		case 4: p_out_L = (uin);delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_L, p_out_L); break;
		case 5: p_out_L = (in);delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_L, p_out_L); break;
		case 6: p_out_L = (ft); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_L, p_out_L);break;
		case 7: p_out_L = (yd);delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_L, p_out_L); break;
		case 8: p_out_L = (mi); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_L, p_out_L);break;
		}
		break;
	case 9: case 10: case 11: case 12: case 13:
		switch (comboBox2->SelectedIndex) {
		case 0: p_out_W = (kg); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_W, p_out_W);break;
		case 1: p_out_W = (g); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_W, p_out_W);break;
		case 2: p_out_W = (mg); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_W, p_out_W);break;
		case 3: p_out_W = (lb); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_W, p_out_W);break;
		case 4: p_out_W = (oz); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_W, p_out_W);break;
		}
		break;
	case 14: case 15: case 16: case 17: case 18: case 19:
		switch (comboBox2->SelectedIndex) {
		case 0: p_out_P = (mW); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_P, p_out_P); break;
		case 1: p_out_P = (W); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_P, p_out_P);  break;
		case 2: p_out_P = (dBm); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_P, p_out_P);  break;
		case 3: p_out_P = (dBW); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_P, p_out_P);  break;
		case 4: p_out_P = (mV); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_P, p_out_P);  break;
		case 5: p_out_P = (V); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_P, p_out_P);  break;
		}
		break;
	case 20: case 21:
		switch (comboBox2->SelectedIndex) {
		case 0: p_out_P = (k); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_P, p_out_P);  break;
		case 1: p_out_P = (dB); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_P, p_out_P);  break;
		}
		break;
	case 22: case 23: case 24:
		switch (comboBox2->SelectedIndex) {
		case 0: p_out_T = (F); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_T, p_out_T); break;
		case 1: p_out_T = (C); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_T, p_out_T);  break;
		case 2: p_out_T = (K); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_T, p_out_T);  break;
		}
		break;
	case 25: case 26: case 27: case 28:
		switch (comboBox2->SelectedIndex) {
		case 0: p_out_N = (BIN); delete p_Converter;
			if (expression != "") p_Converter = new Converter((expression), p_in_N, p_out_N); break;
		case 1: p_out_N = (OCT); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_N, p_out_N);  break;
		case 2: p_out_N = (HEX); delete p_Converter;
			if (expression != "") p_Converter = new Converter((expression), p_in_N, p_out_N);  break;
		case 3: p_out_N = (DEC); delete p_Converter;
			if (expression != "") p_Converter = new Converter(stod(expression), p_in_N, p_out_N);  break;
		}
		break;
	}
}
#pragma endregion


void Projekt_v1::MainPage::AddElementsToComboBox2_Length()
{
	comboBox2->Items->Clear();
	comboBox2->Items->Append("mm");
	comboBox2->Items->Append("cm");
	comboBox2->Items->Append("m");
	comboBox2->Items->Append("km");
	comboBox2->Items->Append("uin");
	comboBox2->Items->Append("in");
	comboBox2->Items->Append("ft");
	comboBox2->Items->Append("yd");
	comboBox2->Items->Append("mi");
}

void Projekt_v1::MainPage::AddElementsToComboBox2_Weight()
{
	comboBox2->Items->Clear();
	comboBox2->Items->Append("kg");
	comboBox2->Items->Append("g");
	comboBox2->Items->Append("mg");
	comboBox2->Items->Append("lb");
	comboBox2->Items->Append("oz");
}

void Projekt_v1::MainPage::AddElementsToComboBox2_Power1()
{
	comboBox2->Items->Clear();
	comboBox2->Items->Append("mW");
	comboBox2->Items->Append("W");
	comboBox2->Items->Append("dBm");
	comboBox2->Items->Append("dBW");
	comboBox2->Items->Append("mV");
	comboBox2->Items->Append("V");
}

void Projekt_v1::MainPage::AddElementsToComboBox2_Power2()
{
	comboBox2->Items->Clear();
	comboBox2->Items->Append("k");
	comboBox2->Items->Append("dB");
}

void Projekt_v1::MainPage::AddElementsToComboBox2_Temp()
{
	comboBox2->Items->Clear();
	comboBox2->Items->Append("F");
	comboBox2->Items->Append("C");
	comboBox2->Items->Append("K");
}

void Projekt_v1::MainPage::AddElementsToComboBox2_Numb()
{
	comboBox2->Items->Clear();
	comboBox2->Items->Append("BIN");
	comboBox2->Items->Append("OCT");
	comboBox2->Items->Append("HEX");
	comboBox2->Items->Append("DEC");
}

void Projekt_v1::MainPage::ButtonConv_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (expression != "") {
		ComboBox2_Run();
		result = to_string(p_Converter->GetOutputVal());

		wstring buff(result.begin(), result.end());
		wstring buff2(expression.begin(), expression.end());
		Output->Text = String(buff2.c_str()).ToString() + " -> " + String(buff.c_str()).ToString();
	}
	else {
		Output->Text = "Wprowadź wartość.";
	}

	result = "";
}

#pragma endregion



