class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length()) return false;
        char[] ch1=new char[128];
        char[] ch2=new char[128];
        for(int i=0;i<s.length();i++)
        {
            int j=(int)s.charAt(i);
            if(ch1[j]=='\0') 
            ch1[j]=t.charAt(i);
            else
            if(ch1[j]!=t.charAt(i)) return false;
        }
        for(int i=0;i<s.length();i++)
        {
            int j=(int)t.charAt(i);
            if(ch2[j]=='\0') 
            ch2[j]=s.charAt(i);
            else
            if(ch2[j]!=s.charAt(i)) return false;
        }
        return true;
    }
}