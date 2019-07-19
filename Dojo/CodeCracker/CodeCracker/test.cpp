#include "pch.h"
//from
//a b c d e f g h i j k l m n o p q r s t u v w x y z
//to
//! ) " ( £ * % & > < @ a b c d e f g h i j k l m n o

//create encrypt/decrypt function

class CodeCracker
{
public:
	
	std::string Encode(const std::string& str)
	{
		std::string result;

		for(int i = 0; i < str.size();i++)
		{
			result.push_back(TranslateCharacter(str[i], encryptedCharacters, unencryptedCharacters));
		}

		return result;
	}

	std::string Decode(const std::string& str)
	{
		std::string result;

		for (int i = 0; i < str.size();i++)
		{
			result.push_back(TranslateCharacter(str[i], unencryptedCharacters, encryptedCharacters));
		}

		return result;

	}


private:
	std::string unencryptedCharacters = "abcdefghijklmnopqrstuvwxyz";
	std::string encryptedCharacters = "!)\"(£*%&><@abcdefghijklmno";

	char TranslateCharacter(char inp, const std::string& from, const std::string& to)
	{
		auto index = to.find_first_of(inp);

		if (index == std::string::npos)
		{
			throw std::exception();
		}

		return from[index];
	}
};

TEST(CodeCrakerTests, ShouldReturnExclamationMarkFor_a) {
	CodeCracker c;

	std::string result = c.Encode("a");

	EXPECT_EQ("!", result);
}

TEST(CodeCrakerTests, ShouldReturnRightBracketFor_b) {
	CodeCracker c;

	std::string result = c.Encode("b");

	EXPECT_EQ(")", result);
}

TEST(CodeCrakerTests, ShouldReturnDoublequoteFor_c) {
	CodeCracker c;

	std::string result = c.Encode("c");

	EXPECT_EQ("\"", result);
}

TEST(CodeCrakerTests, ShouldThrowExceptionForUnexpectedNumber) {
	CodeCracker c;

	EXPECT_THROW(c.Encode("1"), std::exception);
}


TEST(CodeCrakerTests, ShouldEncryptValidWord) {
	CodeCracker c;

	std::string result = c.Encode("word");

	EXPECT_EQ("ldg(", result);
}

TEST(CodeCrakerTests, ShouldDecryptValidWord) {
	CodeCracker c;

	std::string result = c.Decode("ldg(");

	EXPECT_EQ("word", result);
}

TEST(CodeCrakerTests, ShouldEncryptRandomWord) {
	CodeCracker c;

	std::string inp = "asdfcvgbhnjmkluyteehguehuyerhgiuheriugherg";
	std::string result = c.Decode(c.Encode(inp));

	EXPECT_EQ(inp, result);
}

TEST(CodeCrakerTests, ShouldDecryptRandomWord) {
	CodeCracker c;

	std::string inp = "()()()()\"\"\"\"\"\"\"\"\"(((()))))))";
	std::string result = c.Encode(c.Decode(inp));

	EXPECT_EQ(inp, result);
}

TEST(CodeCrakerTests, ShouldEncryptFullWord) {
	CodeCracker c;

	std::string inp = "abcdefghijklmnopqrstuvwxyz";
	std::string result = c.Encode(inp);

	EXPECT_EQ("!)\"(£*%&><@abcdefghijklmno", result);
}

TEST(CodeCrakerTests, ShouldThrowExceptionAgain) {
	CodeCracker c;

	std::string inp = "abcdefghijklmnopqrstuvwxyz1";

	EXPECT_THROW(c.Encode(inp), std::exception);
}

