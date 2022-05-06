#include <string>
#include <msclr/marshal_cppstd.h>

namespace 関数 {
	// 「System::String^」⇒「std::string」へ。.NETのString^文字列を C++のstring文字列へ
	std::string string←String(System::String^ str) {
		std::string native_string = msclr::interop::marshal_as<std::string>(str);
		return native_string;
	}

	// 「std::string」⇒「System::String^」へ。C++のstring文字列を .NETのString^文字列へ
	System::String^ String←string(std::string str) {
		System::String^ managed_string = msclr::interop::marshal_as<System::String^>(str);
		return managed_string;
	}

}