package main



import (
	"github.com/hajimehoshi/ebiten"
	"github.com/hajimehoshi/ebiten/ebitenutil" // This is required to draw debug texts.
	"image/color"
)


var square *ebiten.Image;

func update(screen *ebiten.Image) error {

	screen.Fill(color.NRGBA{0xff, 0xf0, 0xf0, 0xff});

	ebitenutil.DebugPrint(screen, "first ebiten game!");

	if square==nil {
		square, _ = ebiten.NewImage(16, 16, ebiten.FilterNearest);
	}
	square.Fill(color.White);

	opts := &ebiten.DrawImageOptions{};
	opts.GeoM.Translate(64,64);
	screen.DrawImage(square, opts);

	if ebiten.IsKeyPressed(ebiten.KeyUp){
		ebitenutil.DebugPrint(screen, "\nyou pressed up!");
	}
	if ebiten.IsKeyPressed(ebiten.KeyDown){
		ebitenutil.DebugPrint(screen, "\nyou pressed Down!");
	}
	if ebiten.IsKeyPressed(ebiten.KeyRight){
		ebitenutil.DebugPrint(screen, "\nyou pressed Right!");
	}
	if ebiten.IsKeyPressed(ebiten.KeyLeft){
		ebitenutil.DebugPrint(screen, "\nyou pressed Left!");
	}

	if ebiten.IsMouseButtonPressed(ebiten.MouseButtonLeft){
		ebitenutil.DebugPrintAt(screen, "you pressed the Left mouse button", 0, 16);
	}
	
	return nil;
}

func main() {
	if err := ebiten.Run(update, 320, 240, 2, "Hello World!");
	err != nil{
		panic(err);
	}
}

