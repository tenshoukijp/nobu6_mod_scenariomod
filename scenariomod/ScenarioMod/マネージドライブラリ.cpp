#include <string>
#include <msclr/marshal_cppstd.h>

namespace �֐� {
	// �uSystem::String^�v�ˁustd::string�v�ցB.NET��String^������� C++��string�������
	std::string string��String(System::String^ str) {
		std::string native_string = msclr::interop::marshal_as<std::string>(str);
		return native_string;
	}

	// �ustd::string�v�ˁuSystem::String^�v�ցBC++��string������� .NET��String^�������
	System::String^ String��string(std::string str) {
		System::String^ managed_string = msclr::interop::marshal_as<System::String^>(str);
		return managed_string;
	}

}