#pragma once
using namespace System;

namespace GeniusBooks {

	public ref class ComboItem
	{
	private: 
		String^ Name_;
		int Value_;
	
	public: 
		ComboItem(String^ name, int value) {
			this->Name_ = name;
			this->Value_ = value;
		}

		String^ GetName() {
			return Name_;
		}

		int GetValue() {
			return Value_;
		}

		String^ ToString() override {
				return Name_;
		}
	};
}