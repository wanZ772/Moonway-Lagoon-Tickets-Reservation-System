import 'package:flutter/material.dart';

void main() {
  runApp(MaterialApp(home: MainPage()));
}

class MainPage extends StatefulWidget {
  MainPage({Key? key}) : super(key: key);

  @override
  State<MainPage> createState() => _MainPageState();
}

class _MainPageState extends State<MainPage> {
  int adults = 0;
  int kids = 0;
  var price;
  bool isMalaysian = false;
  bool isNotMalaysian = false;
  bool citizenship = false;
  @override
  void calculate_price(adults, kids, citzenship) {
    print("calculate trigered");
    print("$adults, $kids, $citizenship");
    switch (citizenship) {
      case false:
        setState(() {
          if (adults == 2 && kids == 2) {
            price = 120;
          } else {
            price = (50 * kids) + (85 * adults);
          }
        });
        break;
      case true:
        setState(() {
          if (adults == 2 && kids == 2) {
            price = 100;
          } else {
            price = (40 * kids) + (75 * adults);
          }
        });

        break;
    }
    print(price);
  }

  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,
      body: Stack(
        alignment: Alignment.center,
        children: [
          Image.asset(
            './assets/background.jpg',
            height: double.infinity,
            width: double.infinity,
            fit: BoxFit.cover,
          ),
          Positioned(
              top: 40,
              child: Text(
                "Moonway Lagoon",
                style: TextStyle(
                    color: Colors.white,
                    fontWeight: FontWeight.bold,
                    fontSize: 40),
              )),
          Positioned(
              top: 120,
              child: Wrap(
                alignment: WrapAlignment.spaceAround,
                spacing: 20,
                children: [
                  Container(
                    child: IconButton(
                      onPressed: () => setState(() {
                        if (adults > 0) {
                          adults--;
                          calculate_price(adults, kids, citizenship);
                        }
                      }),
                      icon: Icon(Icons.exposure_minus_1),
                      color: Colors.white,
                    ),
                    width: 60,
                    height: 60,
                    decoration: BoxDecoration(
                        border: Border.all(color: Colors.white, width: 2),
                        borderRadius: BorderRadius.circular(12)),
                  ),
                  Container(
                    child: Center(
                      child: Text(
                        textAlign: TextAlign.center,
                        "Adults: $adults",
                        style: TextStyle(
                            color: Colors.black, fontWeight: FontWeight.bold),
                      ),
                    ),
                    width: 130,
                    height: 60,
                    decoration: BoxDecoration(
                        color: Colors.white.withOpacity(.8),
                        border: Border.all(color: Colors.white, width: 2),
                        borderRadius: BorderRadius.circular(12)),
                  ),
                  Container(
                    child: IconButton(
                      onPressed: () => setState(() {
                        adults++;
                        calculate_price(adults, kids, citizenship);
                      }),
                      icon: Icon(Icons.exposure_plus_1),
                      color: Colors.white,
                    ),
                    width: 60,
                    height: 60,
                    decoration: BoxDecoration(
                        border: Border.all(color: Colors.white, width: 2),
                        borderRadius: BorderRadius.circular(12)),
                  ),
                ],
              )),
          Positioned(
              top: 220,
              child: Wrap(
                alignment: WrapAlignment.spaceAround,
                spacing: 20,
                children: [
                  Container(
                    child: IconButton(
                      onPressed: () => setState(() {
                        if (kids > 0) {
                          kids--;
                          calculate_price(adults, kids, citizenship);
                        }
                      }),
                      icon: Icon(Icons.exposure_minus_1),
                      color: Colors.white,
                    ),
                    width: 60,
                    height: 60,
                    decoration: BoxDecoration(
                        border: Border.all(color: Colors.white, width: 2),
                        borderRadius: BorderRadius.circular(12)),
                  ),
                  Container(
                    child: Center(
                      child: Text(
                        textAlign: TextAlign.center,
                        "Kids: $kids",
                        style: TextStyle(
                            color: Colors.black, fontWeight: FontWeight.bold),
                      ),
                    ),
                    width: 130,
                    height: 60,
                    decoration: BoxDecoration(
                        color: Colors.white.withOpacity(.8),
                        border: Border.all(color: Colors.white, width: 2),
                        borderRadius: BorderRadius.circular(12)),
                  ),
                  Container(
                    child: IconButton(
                      onPressed: () => setState(() {
                        kids++;
                        calculate_price(adults, kids, citizenship);
                      }),
                      icon: Icon(Icons.exposure_plus_1),
                      color: Colors.white,
                    ),
                    width: 60,
                    height: 60,
                    decoration: BoxDecoration(
                        border: Border.all(color: Colors.white, width: 2),
                        borderRadius: BorderRadius.circular(12)),
                  ),
                ],
              )),
          Positioned(
              top: 320,
              child: Column(
                children: [
                  Wrap(
                    spacing: 100,
                    children: [
                      Text(
                        "Malaysian",
                        style: TextStyle(
                            color: Colors.white,
                            fontSize: 20,
                            fontWeight: FontWeight.bold),
                      ),
                      Container(
                          width: 20,
                          height: 20,
                          decoration: BoxDecoration(
                              color: Colors.white.withOpacity(.8),
                              border: Border.all(color: Colors.white)),
                          child: Checkbox(
                              checkColor: Colors.blue[200],
                              value: isMalaysian,
                              onChanged: (bool? value) => setState(() {
                                    isMalaysian = value!;
                                    isNotMalaysian = false;
                                    citizenship = true;
                                    calculate_price(adults, kids, citizenship);
                                  })))
                    ],
                  ),
                  SizedBox(
                    height: 10,
                  ),
                  Wrap(
                    spacing: 60,
                    children: [
                      Text(
                        "Non-Malaysian",
                        style: TextStyle(
                            color: Colors.white,
                            fontSize: 20,
                            fontWeight: FontWeight.bold),
                      ),
                      Container(
                          width: 20,
                          height: 20,
                          decoration: BoxDecoration(
                              color: Colors.white.withOpacity(.8),
                              border: Border.all(color: Colors.white)),
                          child: Checkbox(
                              checkColor: Colors.blue[200],
                              value: isNotMalaysian,
                              onChanged: (bool? value) => setState(() {
                                    isNotMalaysian = value!;
                                    isMalaysian = false;
                                    citizenship = false;
                                    calculate_price(adults, kids, citizenship);
                                  })))
                    ],
                  )
                ],
              )),
          Positioned(
            top: 420,
            child: Text(
              (price != null) ? "Total Price: RM$price" : "Total Price: RM0",
              style: TextStyle(
                  color: Colors.white,
                  fontSize: 20,
                  fontWeight: FontWeight.bold),
            ),
          ),
          Positioned(
              top: 620,
              child: Container(
                width: 250,
                height: 60,
                child: FlatButton.icon(
                  onPressed: () => print(1),
                  icon: Icon(
                    Icons.payments_outlined,
                    color: Colors.white,
                  ),
                  label: Text(
                    "Make Payment",
                    style: TextStyle(
                        color: Colors.white,
                        fontSize: 20,
                        fontWeight: FontWeight.bold),
                  ),
                ),
                decoration: BoxDecoration(
                    color: Colors.green[400],
                    border: Border.all(
                      color: Colors.white,
                    ),
                    borderRadius: BorderRadius.circular(20)),
              ))
        ],
      ),
    );
  }
}
