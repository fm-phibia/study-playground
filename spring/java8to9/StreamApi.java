import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Stream;

public class StreamApi {
  public static void useTakeWhile() {
    List<Integer> list = List.of(5, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1);
    list.stream()
        .takeWhile(i -> i < 5)
        .forEach(System.out::println);
  }

  public static void useDropWhile() {
    List<Integer> list = List.of(1, 2, 3, 4, 5, 5, 4, 3, 2, 1);
    list.stream()
        .dropWhile(i -> i < 5)
        .forEach(System.out::println);
  }

  public static void useOfNullable() {
    List<Integer> list = List.of(1, 2, 3);
    Map<Integer, String> map = new HashMap<>() {
      {
        put(1, "one");
        put(2, "two");
        put(4, "four");
      }
    };
    list.stream()
        .map(map::get)
        .flatMap(Stream::ofNullable)
        .forEach(System.out::println);
  }
}
