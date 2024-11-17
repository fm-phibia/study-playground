import java.io.BufferedReader;
import java.io.FileReader;

public class TryWithResources {
  public void useTryWithResources() throws Exception {

    // このように実装が可能
    BufferedReader br = new BufferedReader(new FileReader("tryWithResources.txt"));

    try (br) {
      String line;
      while ((line = br.readLine()) != null) {
        System.out.println(line);
      }
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
  }
}
