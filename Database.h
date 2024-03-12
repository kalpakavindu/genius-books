#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::SqlClient;
using namespace System::Data;
using namespace System::Text;
using namespace System::Threading::Tasks;

ref class Database
{
private:
	String^ connectionString = R"(Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=E:\.data\MicrosoftSQLServerDatabases\DB_GeniusBooks_CPP.mdf;Integrated Security=True;Connect Timeout=30;Encrypt=True)";
	SqlConnection^ connection;
	SqlDataAdapter^ adapter;
	DataTable^ table;
	SqlCommand^ command;

public:
	Database(void) {
		connectionString = gcnew String(connectionString->ToCharArray());
		connection = gcnew SqlConnection(connectionString);
		command = gcnew SqlCommand();
		command->Connection = connection;
	}

	// Retrieve data from the database
	DataTable^ GetData(String^ query) {
		table = gcnew DataTable();
		adapter = gcnew SqlDataAdapter(query, connectionString);
		adapter->Fill(table);
		return table;
	}

	// Execute a query to the database
	int SetData(String^ query) {
		int rowsAffected = -1;
		if (connection->State == ConnectionState::Closed) {
			connection->Open();
		}
		command->CommandText = query;
		rowsAffected = command->ExecuteNonQuery();
		return rowsAffected;
	}
};