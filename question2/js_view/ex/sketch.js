function setup() {
  createCanvas(720,400);
  background(100);

  var d = 70;
  var p1 = d;
  var p2 = p1+d;
  var p3 = p2+d;
  var p4 = p3+d;

  line(p3, p3, p2, p3);
}

function draw() {
  // rect(100,200, 75, 150);


  line(100, 100, 100, 100);
  stroke(250);
  p2 = p2 + d/10;
  line(p2, p3, p2, p2);
  line(p2, p2, p3, p2);
  line(p3, p2, p3, p3);



}
