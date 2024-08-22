package item18;

import java.util.List;

public class EvenNumberCollection extends SecureCollection {

    @Override
    protected boolean isValid(Integer item) {
        System.out.println("override called");
        return super.isValid(item) && item % 2 == 0;
    }
    //test
    public static void main(String[] args) {
        EvenNumberCollection ec = new EvenNumberCollection();
        try {
            ec.addItem(1);
        } catch (Exception e) {
            System.out.println("addItem() failed");
        }
        try {
            ec.addAllItems(List.of(2, 3, 4, 5, 6, 7, 8, 9, 10));
        } catch (Exception e) {
            System.out.println("addAllItems() failed");
        }

    }
}
