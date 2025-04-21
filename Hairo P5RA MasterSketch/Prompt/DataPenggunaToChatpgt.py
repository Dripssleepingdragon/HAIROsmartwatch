String buildPersonalPrompt(String message) {
  String name = "Raka";
  String favFood = "sate madura";
  String job = "developer";

  return "Nama saya " + name + ". Saya suka " + favFood + " dan bekerja sebagai " + job + 
         ". Tolong beri respons sebagai teman dekat saya: " + message;
}
