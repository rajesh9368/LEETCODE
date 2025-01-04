class Solution {

//     class Solution {
//     public boolean hasMatch(String s, String p) {
//         HashMap<Character,Integer> mp1 = new HashMap<>();
//         HashMap<Character,Integer> mp2 = new HashMap<>();
//         for(int i=0;i<s.length();i++){
    public boolean hasMatch(String s, String p) {
int sti=p.indexOf('*');
if(sti==-1) return s.equals(p);
String l=p.substring(0,sti),r=p.substring(sti+1);
int li=s.indexOf(l);
if(li==-1) return false;
int ri=s.lastIndexOf(r);
if(ri==-1) return false;
return li+l.length()<=ri;
}
//             char sh = s.charAt(i);
//             if(!mp1.containsKey(sh)) mp1.put(sh,1);
//             else mp1.put(sh,mp1.get(sh)+1);
//         }
//     for(int i=0;i<p.length();i++){
//             char ph = p.charAt(i);
//             if(!mp2.containsKey(ph)) mp2.put(ph,1);
//             else mp2.put(ph,mp2.get(ph)+1);
//         }
// for(int i=0;i<p.length();i++){
//     if(p.charAt(i)=='*') continue;
//     if(mp1.get(p.charAt(i))!=mp2.get(p.charAt(i))) return false;
// }
// return true;
// }
// }

}