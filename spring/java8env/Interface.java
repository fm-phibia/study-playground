public interface Interface {

  public void getAnything();

  private void privateMethod() {
    System.out.println("privateMethod");
  }

  default void defaultMethod() {
    privateMethod();
  }
}
