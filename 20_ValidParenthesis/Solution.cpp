class Solution {
public:
    bool isValid(string s) {
        bool res;
        for(int i = 0; i < s.size(); i++)
        {
            char c = s.back();
            s.pop_back();
            res = false;
            switch(c)
            {
                case(')'):
                {
                    while((c != '(') && s.size() > 0)
                    {
                        c = s.back();
                        s.pop_back();
                        if(c == '(')
                        {
                            res = true;
                        }
                    }
                }
                break;
                case('}'):
                {
                    while((c != '{') && s.size() > 0)
                    {
                        c = s.back();
                        s.pop_back();
                        if(c == '{')
                        {
                            res = true;
                        }
                    }
                }
                break;
                case(']'):
                {
                    while((c != '[') && s.size() > 0)
                    {
                        c = s.back();
                        s.pop_back();
                        if(c == '[')
                        {
                            res = true;
                        }
                    }
                }
                break;
            }
        }
        return res;
    }
};
