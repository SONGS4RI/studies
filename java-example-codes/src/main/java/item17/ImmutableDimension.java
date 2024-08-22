package item17;

public final class ImmutableDimension {
    private final int width;
    private final int height;

    public ImmutableDimension(int width, int height) {
        this.width = width;
        this.height = height;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public ImmutableDimension getSize() {
        return this;
    }
}
