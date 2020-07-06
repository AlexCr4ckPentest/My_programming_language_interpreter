#ifndef TOKEN_CHAR_H
#define TOKEN_CHAR_H

class TokenChar
{
public:
    inline TokenChar() noexcept
        : m_character {}
    {}

    inline TokenChar(const char character) noexcept
        : m_character {character}
    {}

    inline TokenChar(const TokenChar& other) noexcept
    { m_character = other.m_character; }

    inline bool isNumber() const noexcept
    { return (m_character >= '0' && m_character <= '9'); }

    inline bool isLetter() const noexcept
    { return ((m_character >= 'A' && m_character <= 'z') && (m_character >= 'a' || m_character <= 'Z')); }

    bool isLetterOrNumber() const noexcept
    { return (isLetter() || isNumber()); }

    inline bool operator ==(const char character) const noexcept
    { return (m_character == character); }

    inline bool operator ==(const TokenChar& other) const noexcept
    { return (m_character == other.m_character); }

    inline void operator =(const char character)
    { m_character = character; }

    inline void operator =(const TokenChar& other)
    { m_character = other.m_character; }

    inline char toStdChar() const noexcept
    { return m_character; }

private:
    char m_character {};
};

#endif // TOKEN_CHAR_H
