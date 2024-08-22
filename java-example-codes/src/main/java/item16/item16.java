package item16;

public class item16 {
    public static void main(String[] args) {
//        item17.ImmutableDimension immutableDimension = new item17.ImmutableDimension(10, 25);
//        item17.ImmutableDimension a = immutableDimension.getSize();
//        item17.ImmutableDimension b = immutableDimension.getSize();
//        System.out.println(a.equals(b));// false

        String s1 = new String("example");
        String s2 = s1.intern();

        String s3 = "example";

        System.out.println(s1 == s2);// false
        System.out.println(s2 == s3);// true
        System.out.println(s1 == s3);// false


    }

}