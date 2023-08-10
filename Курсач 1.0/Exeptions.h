#pragma once
#include <exception>
#include <string>

class DateTimeExeption : public std::exception
{
public:
	static std::string what()
	{
		return "Введены невозможные значения";
	}
};
class UsualExeption : public std::exception
{
public:
	static std::string what()
	{
		return "Операция прервана";
	}
};

class AddException : public std::exception
{
public:
	static std::string what()
	{
		return "Объект не может быть добавлен";
	}
};
class DeleteException : public std::exception
{
public:
	static std::string what()
	{
		return "Объект не может быть добавлен";
	}
};
class FileException : public std::exception
{
public:
	static std::string what()
	{
		return "Операция отменена: ошибка открытия файла";
	}
};
class FindException : public std::exception
{
public:
	static std::string what()
	{
		return "Элемент не найден";
	}
};
class EscException : public std::exception
{
public:
	static std::string what()
	{
		return "Операция была прервана";
	}
};
class TransactionNextException : public std::exception
{
public:
	static std::string what()
	{
		return "Следующего элемента не существует";
	}
};
class TransactionPreviousException : public std::exception
{
public:
	static std::string what()
	{
		return "Предыдущего элемента не существует";
	}
};
class OverflowException : public std::exception
{
public:
	static std::string what()
	{
		return "Больше элементов быть добавлено не может";
	}
};