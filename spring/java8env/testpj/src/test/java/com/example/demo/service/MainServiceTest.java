package com.example.demo.service;

import static org.junit.Assert.assertEquals;
import org.springframework.boot.test.context.SpringBootTest;
import org.junit.jupiter.api.Test;

@SpringBootTest
public class MainServiceTest {

  @Test
  public void testGetUserName() {
    MainService mainService = new MainService();
    String result = mainService.getUserName("John");
    assertEquals("Hello, John!", result);
  }
}