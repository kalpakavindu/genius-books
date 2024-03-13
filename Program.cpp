#include "./Forms/AdminForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GeniusBooks::AdminForm authForm;

	Application::Run(% authForm);
}