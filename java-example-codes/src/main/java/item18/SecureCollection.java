package item18;

import java.util.ArrayList;
import java.util.List;

public class SecureCollection {
    protected List<Integer> items = new ArrayList<>();

    public void addItem(Integer item) {
        if (isValid(item)) {
            items.add(item);
        } else {
            throw new IllegalArgumentException("Invalid item");
        }
    }

    protected boolean isValid(Integer item) {
        return item != null;
    }

    public List<Integer> getItems() {
        return items;
    }
    public void addAllItems(List<Integer> items) {
        for (Integer item : items) {
            addItem(item);
        }
    }
}