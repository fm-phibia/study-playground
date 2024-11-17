import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ImmutableList {
  public static void useLists() {
    // 可変リスト
    List<String> mutableList = new ArrayList<>(Arrays.asList("a", "b", "c"));
    mutableList.set(0, "d");
    for (String s : mutableList) {
      System.out.println(s);
    }

    // 不変リスト
    List<String> immutableList = List.of("a", "b", "c");
    immutableList.set(0, "d");
    for (String s : immutableList) {
      System.out.println(s);
    }
  }
}
