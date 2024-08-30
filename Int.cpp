#include"Int.h"
Int::Int(){
    isNeg = false;
    data.resize(1);
    data[0]=0;
    digit=1;
}

Int::Int(const string num){
    int start,end;
    end = num.size();
    digit=end;
    if(num[0]=='-'){
        isNeg = true;
        start = 1;
        digit--;
    }else{
        isNeg = false;
        start = 0;
    }
    
    data.resize(end-start);

    for(int i=end-1,j=0;i>=start;i--,j++){
        if(num[i]<'0'||num[i]>'9'){
            isNeg = false;
            data[0]=0;
            digit=1;
            return;
        }
        data[j]=num[i]-'0';
    }

    for (int i = data.size() - 1; i >= 0; i--)
    {
        if(data[i]==0) digit--;
        else break;
    }

    if(digit==0) {
        isNeg = false;
        data.resize(1);
        data[0]=0;
        digit=1;
    }else{
        data.resize(digit);
    }

}

Int::Int(const char* num){
    if(num==nullptr){
        isNeg = false;
        data[0]=0;
        return;
    }

    int start=0,end;

    for (end = 0; num[end]!=0;end++);

    digit=end;

    if(num[0]=='-'){
        isNeg=true;
        start++;
        digit--;
    }else{
        isNeg=false;
    }

    data.resize(end-start);

    for (int i = 0,j=end-1;j>=start ; i++,j--)
    {
        if(num[j]<'0'||num[j]>'9'){
            isNeg = false;
            data[0]=0;
            digit=1;
            return;
        }
        data[i]=num[j]-'0';
    }

    for (int i = data.size() - 1; i >= 0; i--)
    {
        if(data[i]==0) digit--;
        else break;
    }

    if(digit==0) {
        isNeg = false;
        data.resize(1);
        data[0]=0;
        digit=1;
    }else{
        data.resize(digit);
    }


}

Int::Int(char num){


    if(num<0){
        isNeg=true;
        num=-num;
    }else{
        isNeg=false;
    }

    

    do{
        data.push_back(num%10);
        num/=10;
    }while (num);

    digit=data.size();
    
}

Int::Int(unsigned char num){
    isNeg=false;

    do{
        data.push_back(num%10);
        num/=10;
    }while (num);

    digit=data.size();
}

Int::Int(short num){
    if(num<0){
        isNeg=true;
        num=-num;
    }else{
        isNeg=false;
    }

    do{
        data.push_back(num%10);
        num/=10;
    }while (num);

    digit=data.size();
}
Int::Int(unsigned short num){
    isNeg=false;

    do{
        data.push_back(num%10);
        num/=10;
    }while (num);

    digit=data.size();
}

Int::Int(int num){
    if(num<0){
        isNeg=true;
        num=-num;
    }else{
        isNeg=false;
    }

    do{
        data.push_back(num%10);
        num/=10;
    }while (num);

    digit=data.size();
}
Int::Int(unsigned int num){
    isNeg=false;

    do{
        data.push_back(num%10);
        num/=10;
    }while (num);

    digit=data.size();
}

Int::Int(long num){
    if(num<0){
        isNeg=true;
        num=-num;
    }else{
        isNeg=false;
    }

    do{
        data.push_back(num%10);
        num/=10;
    }while (num);

    digit=data.size();
}

Int::Int(unsigned long num){
    isNeg=false;
    do{
        data.push_back(num%10);
        num/=10;
    }while (num);

    digit=data.size();
}


Int::Int(long long num){
    if(num<0){
        isNeg=true;
        num=-num;
    }else{
        isNeg=false;
    }

    do{
        data.push_back(num%10);
        num/=10;
    }while (num);

    digit=data.size();
}

Int::Int(unsigned long long num){
    isNeg=false;

    do{
        data.push_back(num%10);
        num/=10;
    }while (num);

    digit=data.size();
}

ostream& operator<<(ostream &out, const Int &num){
    if(num.isNeg) out<<'-';
    for (int i = num.digit - 1; i >= 0; i--)
    {
        out<<char(num.data[i]+'0');
    }
    return out;
}

istream& operator>>(istream &in, Int &num){
    string s;
    in>>s;
    num=Int(s);
    return in;
}


bool operator==(const Int &num1, const Int &num2){
    if(num1.digit!=num2.digit) return false;
    if(num1.isNeg!=num2.isNeg) return false;
    for (int i = 0; i < num1.digit; i++)
    {
        if(num1.data[i]!=num2.data[i]) return false;
    }
    return true;
}
bool operator!=(const Int &num1, const Int &num2){
    if(num1.digit!=num2.digit) return true;
    if(num1.isNeg!=num2.isNeg) return true;
    for (int i = 0; i < num1.digit; i++)
    {
        if(num1.data[i]!=num2.data[i]) return true;
    }
    return false;
}

bool operator<(const Int &num1, const Int &num2){
    if(num1.isNeg!=num2.isNeg) return num1.isNeg;
    if(num1.digit!=num2.digit) return num1.digit<num2.digit;

    for (int i = num1.digit - 1; i >= 0; i--){
        if(num1.data[i]!=num2.data[i]) return num1.data[i]<num2.data[i];
    }

    return false;
}

bool operator<=(const Int &num1, const Int &num2){
    if(num1.isNeg!=num2.isNeg) return num1.isNeg;
    if(num1.digit!=num2.digit) return num1.digit<num2.digit;

    for (int i = num1.digit - 1; i >= 0; i--){
        if(num1.data[i]!=num2.data[i]) return num1.data[i]<num2.data[i];
    }

    return true;
}

bool operator>(const Int &num1, const Int &num2){
    if(num1.isNeg!=num2.isNeg) return num2.isNeg;
    if(num1.digit!=num2.digit) return num1.digit>num2.digit;

    for (int i = num1.digit - 1; i >= 0; i--){
        if(num1.data[i]!=num2.data[i]) return num1.data[i]>num2.data[i];
    }

    return false;
}

bool operator>=(const Int &num1, const Int &num2){
    if(num1.isNeg!=num2.isNeg) return num2.isNeg;
    if(num1.digit!=num2.digit) return num1.digit>num2.digit;

    for (int i = num1.digit - 1; i >= 0; i--){
        if(num1.data[i]!=num2.data[i]) return num1.data[i]>num2.data[i];
    }

    return true;
}

Int Int::operator-() const{
    Int res=Int(*this);
    res.isNeg=!res.isNeg;
    return res;
}

Int operator+(const Int &num1, const Int &num2){
    if(num1.isNeg!=num2.isNeg){
        if(num1.isNeg){
            return num2-(-num1);
        }else{
            return num1-(-num2);
        }
    }
    
    Int res;
    res.isNeg=num1.isNeg;
    int i=0,carry=0;
    res.data.resize(max(num1.digit,num2.digit)+1);
    while(i<num1.digit && i<num2.digit){
        res.data[i]=num1.data[i]+num2.data[i]+carry;
        if(res.data[i]>=10){
            res.data[i]-=10;
            carry=1;
        }else carry=0;
        i++;
    }

    while(i<num1.digit){
        res.data[i]=num1.data[i]+carry;
        if(res.data[i]>=10){
            res.data[i]-=10;
            carry=1;
        }else carry=0;
        i++;
    }

    while(i<num2.digit){
        res.data[i]=num2.data[i]+carry;
        if(res.data[i]>=10){
            res.data[i]-=10;
            carry=1;
        }else carry=0;
        i++;
    }

    if(carry){
        res.data[i]=1;
        i++;
    }

    res.digit=i;
    res.data.resize(i);
    return res;
}

Int operator-(const Int &num1, const Int &num2){
    if(num1.isNeg!=num2.isNeg){
        if(num1.isNeg)
            return -(num2+(-num1));
        else
            return num1+(-num2);
    }

    if(num1.isNeg) return (-num2-(-num1));
    if(num1<num2) return -(num2-num1);
    if(num1==num2) return Int(0);

    Int ret;
    ret.isNeg=0;
    ret.data.resize(num1.digit);
    int i=0,carry=0;
    while (i<num1.digit&&i<num2.digit)
    {
        ret.data[i]=num1.data[i]-num2.data[i]-carry;
        if(ret.data[i]<0){
            ret.data[i]+=10;
            carry=1;
        }
        else
            carry=0;
        i++;
    }

    while (i<num1.digit)
    {
        ret.data[i]=num1.data[i]-carry;
        if(ret.data[i]<0){
            ret.data[i]+=10;
            carry=1;
        }
        else
            carry=0;
        i++;
    }

    ret.digit=num1.digit;

    for(int i = num1.digit-1 ; i >= 0 ; i--)
    {
        if(ret.data[i]==0){
            ret.data[i]=0;
            ret.digit--;
        }else{
            break;
        }
    }
    return ret;
}

Int operator*(const Int &num1, const Int &num2){
    if(num1==0||num2==0) return Int(0);

    Int ret;
    int carry=0;
    ret.isNeg=(num1.isNeg!=num2.isNeg);
    ret.digit=num1.digit+num2.digit;
    ret.data.resize(ret.digit);
    int i,j;
    for (i = 0; i < num1.digit; i++)
    {
        for (j = 0; j <num2.digit; j++)
        {
            ret.data[i+j]+=num1.data[i]*num2.data[j];
            if(ret.data[i+j]>=10){
                ret.data[i+j+1]+=ret.data[i+j]/10;
                ret.data[i+j]%=10;
            }
        }
    }
    
    while (ret.data[ret.digit-1]==0&&ret.digit>=0)
    {
        ret.digit--;
    }
    return ret;
}

Int operator/(const Int &num1, const Int &num2){
    if(num1==0||num1<num2) return Int(0);
    if(num2==0) {cout<<"Divide by zero!";return Int(0);}
    if(num1==num2) return Int(1);

    Int ret;
    ret.isNeg=(num1.isNeg!=num2.isNeg);

    int i=0;
    Int tmp=num2;
    while(num1>=tmp){
        tmp=tmp*10;
        i++;
    }
    ret.digit=i;
    ret.data.resize(i);
    Int a=num1;
    while(i>=0){
        if(a>=tmp){
            ret.data[i]++;
            a=a-(tmp);
        }else{
            i--;
            for (int _i = 0; _i < tmp.digit; _i++)
            {
                tmp.data[_i]=tmp.data[_i+1];
            }
            tmp.data[tmp.digit-1]=0;
            tmp.digit--;
        }
    } 
    return ret;
}

Int operator%(const Int &num1, const Int &num2){
    if(num2==0) return Int(num1);
    if(num1==0) return Int(0);
    if(num1<num2) return num1;
    if(num1==num2) return Int(0);
    Int ret;
    ret.isNeg=(num1.isNeg!=num2.isNeg);

    int i=0;
    Int tmp=num2;
    while(num1>=tmp){
        tmp=tmp*10;
        i++;
    }
    ret.digit=i;
    ret.data.resize(i);
    Int a=num1;
    while(i>=0){
        if(a>=tmp){
            ret.data[i]++;
            a=a-(tmp);
        }else{
            i--;
            for (int _i = 0; _i < tmp.digit; _i++)
            {
                tmp.data[_i]=tmp.data[_i+1];
            }
            tmp.data[tmp.digit-1]=0;
            tmp.digit--;
        }
    } 
    return a;
}


Int& Int::operator+=(const Int &num){
    *this=*this+num;
    return *this;
}

Int& Int::operator-=(const Int &num){
    *this=*this-num;
    return *this;
}

Int& Int::operator*=(const Int &num){
    *this=*this*num;
    return *this;
}

Int& Int::operator/=(const Int &num){
    *this=*this/num;
    return *this;
}

Int& Int::operator%=(const Int &num){
    *this=*this%num;
    return *this;
}

Int& Int::operator++(){
    *this=*this+Int(1);
    return *this;
}

Int Int::operator++(int){
    Int tmp=*this;
    *this=*this+Int(1);
    return tmp;
}


Int& Int::operator--(){
    *this=*this-Int(1);
    return *this;
}

Int Int::operator--(int){
    Int tmp=*this;
    *this=*this-Int(1);
    return tmp;
}

Int powInt(Int num1, Int num2){
    Int res(1);
    while(num2>0){
        if(num2%2==1) res*=num1;
        num1*=num1;
        num2/=2;
    }
    return res;
}

string Int::ToString() const{
    string res="";
    if(isNeg) res+="-";
    for (int i = digit-1; i >= 0; i--)
    {
        res+=char(data[i]+'0');
    }
    return res;
}

char* Int::ToCString() const{
    char* res=new char[digit+2];
    if(isNeg){ res[0]='-';res[digit+1]='\0';}
    else{res[digit]='\0';}
    for (int i = digit-1; i >= 0; i--)
    {
        res[i+1]=char(data[i]+'0');
    }
    return res;
}

long long Int::ToInt() const{
    long long res=0;
    for (int i = digit-1; i >= 0; i--)
    {
        res=res*10+data[i];
    }
    return res;
}

string Int::ToBinary() const{
    string res="";
    Int tmp=*this;
    while(tmp>0){
        res=(tmp%2).ToString()+res;
        tmp/=2;
    }
    return res;
}

Int sqrtInt(Int num){
    Int res(0);
    Int l(0),r=num;
    while(l<=r){
        Int mid=(l+r)/2;
        if(mid*mid<=num){
            res=mid;
            l=mid+Int(1);
        }else{
            r=mid-Int(1);
        }
    }
    return res;
}