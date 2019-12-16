package main



import (
    "github.com/hajimehoshi/ebiten"
    "github.com/hajimehoshi/ebiten/ebitenutil" // This is required to draw debug texts.
)



func update(screen *ebiten.Image) error {
	ebitenutil.DebugPrint(screen, "first ebiten game!");
	return nil;
}

func main() {
	if err := ebiten.Run(update, 320, 240, 2, "Hello World!");
	err != nil{
		panic(err);
	}
}


