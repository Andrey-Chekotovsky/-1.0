#pragma once
#include <exception>
#include <string>

class DateTimeExeption : public std::exception
{
public:
	static std::string what()
	{
		return "������� ����������� ��������";
	}
};
class UsualExeption : public std::exception
{
public:
	static std::string what()
	{
		return "�������� ��������";
	}
};

class AddException : public std::exception
{
public:
	static std::string what()
	{
		return "������ �� ����� ���� ��������";
	}
};
class DeleteException : public std::exception
{
public:
	static std::string what()
	{
		return "������ �� ����� ���� ��������";
	}
};
class FileException : public std::exception
{
public:
	static std::string what()
	{
		return "�������� ��������: ������ �������� �����";
	}
};
class FindException : public std::exception
{
public:
	static std::string what()
	{
		return "������� �� ������";
	}
};
class EscException : public std::exception
{
public:
	static std::string what()
	{
		return "�������� ���� ��������";
	}
};
class TransactionNextException : public std::exception
{
public:
	static std::string what()
	{
		return "���������� �������� �� ����������";
	}
};
class TransactionPreviousException : public std::exception
{
public:
	static std::string what()
	{
		return "����������� �������� �� ����������";
	}
};
class OverflowException : public std::exception
{
public:
	static std::string what()
	{
		return "������ ��������� ���� ��������� �� �����";
	}
};