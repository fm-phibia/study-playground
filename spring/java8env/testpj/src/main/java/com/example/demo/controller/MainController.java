package com.example.demo.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import com.example.demo.service.MainService;

@Controller
public class MainController {

  // "/aaa"へのGETリクエストを受け付けるメソッド
  @GetMapping("/aaa")
  @ResponseBody
  public String getUserName(@RequestParam String name) {
    MainService service = new MainService();
    return service.getUserName(name);
  }

}
