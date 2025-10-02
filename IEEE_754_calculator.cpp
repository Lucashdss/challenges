#include <iostream>
#include <bitset>

using namespace std;

bitset<8> int_to_binary(float &number);
bitset<23> frac_to_binary(float &number);
int FindFirstOne(bitset<8> &int_bits);
bitset<23> FindMantissa(int const &IntFirstOne, bitset<8> &int_bits, bitset<23> &frac_bits);
bitset<32> FindIEEE(float &number, int const &IntFirstOne, bitset<8> &int_bits, bitset<23> &mantissa);

int main()
{
    float *number = new float;

    cout << "Enter a floating-point number: ";
    cin >> *number;

    bitset<8> Binary_num = int_to_binary(*number);
    bitset<23> Binary_frac = frac_to_binary(*number);
    bitset<23> Mantissa = FindMantissa(FindFirstOne(Binary_num), Binary_num, Binary_frac);
    bitset<32> IEEE = FindIEEE(*number, FindFirstOne(Binary_num), Binary_num, Mantissa);

    delete number;
    cout << "The binary representation of the integer part is: " << Binary_num << endl;
    cout << "The binary representation of the fractional part is: " << Binary_frac << endl;
    cout << "The Mantissa is: " << Mantissa << endl;
    cout << "The IEEE 754 representation is: " << IEEE << endl;

    return 0;
}

bitset<8> int_to_binary(float &number)
{
    bitset<8> int_bits(static_cast<int>(number));

    return int_bits;
}

bitset<23> frac_to_binary(float &number)
{
    float frac_part = number - static_cast<int>(number);
    bitset<23> frac_bits;

    for (int i = 0; i < 23; ++i)
    {
        frac_part *= 2;
        if (frac_part >= 1)
        {
            frac_bits[22 - i] = 1;
            frac_part -= 1;
        }
        else
        {
            frac_bits[22 - i] = 0;
        }
    }

    return frac_bits;
}

int FindFirstOne(bitset<8> &int_bits)
{
    int IntIndex{};
    for (int i = 7; i >= 0; --i)
    {
        if (int_bits[i] == 1)
        {
            IntIndex = i;
            break;
        }
    }

    return IntIndex;
}

bitset<23> FindMantissa(int const &IntFirstOne, bitset<8> &int_bits, bitset<23> &frac_bits)
{
    string Int_to_string = int_bits.to_string();
    string Frac_to_string = frac_bits.to_string();

    for (int i = 0; i < Int_to_string.size(); ++i)
    {
        if (Int_to_string[i] == '1')
        {
            Int_to_string = Int_to_string.substr(i + 1);
            break;
        }
    }
    string MantissaString = Int_to_string + Frac_to_string;
    if (MantissaString.length() > 23)
    {
        MantissaString.substr(0, 23);
    }
    bitset<23> mantissa{MantissaString};

    return mantissa;
}

bitset<32> FindIEEE(float &number, int const &IntFirstOne, bitset<8> &int_bits, bitset<23> &mantissa)
{
    string Ieee{};
    if (number < 0)
    {
        Ieee += '1';
    }
    else
    {
        Ieee += '0';
    }

    int Exponent = (IntFirstOne + 127);
    bitset<8> ExponentBits(Exponent);
    Ieee += ExponentBits.to_string();
    Ieee += mantissa.to_string();
    bitset<32> IeeeBits(Ieee);

    return bitset<32>(Ieee);
}