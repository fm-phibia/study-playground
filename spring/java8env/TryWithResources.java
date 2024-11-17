import java.io.BufferedReader;
import java.io.FileReader;

public class TryWithResources {
  public void useTryWithResources() {
    try (BufferedReader br = new BufferedReader(new FileReader("tryWithResources.txt"))) {
      String line;
      while ((line = br.readLine()) != null) {
        System.out.println(line);
      }
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
  }
}
