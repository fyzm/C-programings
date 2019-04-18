


string::size_type find_char(const string &s,char c,
                             string::size_type &occurs)
  {
    auto ret = s.size();
    occurs = 0;
    for(decltype(ret) i = 0; i !=s.size();++i){
        if(s[i] == c) {
          if (ret == s.size())
              ret = i; //记录c 第一次出现的位置
              ++occurs;
        }
    }
    return ret; //出现的次数通过occurs引式返回
  }
