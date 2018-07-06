//
// MainPage.xaml.h
// Deklaracja klasy MainPage.
//

#pragma once

#include "MainPage.g.h"
#include <string>

using std::string;

namespace Projekt_v1
{
	/// <summary>
	/// Pusta strona, która może być używana samodzielnie lub do której można nawigować wewnątrz ramki.
	/// </summary>
	public ref class MainPage sealed
	{
		string expression;
		string result;
		float result_f;
		string answer;
		Calculator* p_Calc;
		Converter* p_Converter;

		LengthConvTypes p_in_L;
		LengthConvTypes p_out_L;
		WeightConvTypes p_in_W;
		WeightConvTypes p_out_W;
		PowerConvTypes p_in_P;
		PowerConvTypes p_out_P;
		TempConvTypes p_in_T;
		TempConvTypes p_out_T;
		NumSysConvTypes p_in_N;
		NumSysConvTypes p_out_N;

	public:
		MainPage();

	private:

#pragma region Special Buttons
		void ButtonCl_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonClr_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

		void ButtonHEX_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonOCT_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonBIN_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

		void ButtonAdd_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonSub_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonMult_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonDiv_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonPow_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonMod_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonLeftParan_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonRightParan_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonA_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonB_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonC_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonD_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonE_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonF_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonAns_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonEqu_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

		void ComboBox_SelectionChanged1(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);
		void ComboBox_SelectionChanged2(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);
		void ComboBox2_Run();
		void ButtonConv_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void AddElementsToComboBox2_Length();
		void AddElementsToComboBox2_Weight();
		void AddElementsToComboBox2_Power1();
		void AddElementsToComboBox2_Power2();
		void AddElementsToComboBox2_Temp();
		void AddElementsToComboBox2_Numb();
#pragma endregion

#pragma region Numbers Buttons
		void Button1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button4_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button5_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button6_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button7_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button8_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button9_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button0_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
#pragma endregion

	};
}
