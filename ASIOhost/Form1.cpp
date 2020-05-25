//#include "stdafx.h"
 #include "Form1.h"
namespace ASIOmarker {

	void Form1::getASIODeviceItems(System::Windows::Forms::ComboBox^ comboBox) {

		comboBox->Items->Clear();
		
		AsioDriverList* pdriverList = new AsioDriverList();
		
			for (int i = 0; i < pdriverList->asioGetNumDev() ; i++)
			{
				char driverName[64];
				pdriverList->asioGetDriverName(i, driverName, 64);
				String^ clistr = gcnew String(driverName);
				comboBox->Items->Add(clistr);

			}
			comboBox->SelectedIndex = 0;

		delete pdriverList;
	};


	void Form1::initASIO(char *name) {

		if (ASIOHostInit(name))
		{
			
		} 
		
	}
};


