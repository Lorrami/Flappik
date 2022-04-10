using System;
using System.Collections.Generic;
using System.IO;
using SFML.Graphics;
using SFML.System;
using SFML.Window;

namespace Flappik
{
    public class Engine
    {
        private static RectangleShape _bird = new RectangleShape(), _snitch, _texture = new RectangleShape();
        private static RenderWindow _window;
        private static readonly Random _rnd = new Random();

        private static readonly List<GameObjects> AllBlocks = new List<GameObjects>();
        private static int _q = _rnd.Next(-200, 201), _q1 = _rnd.Next(-200, 201);
        private static double _progressCount = 0, _maxProgress = 0;
        private static float _speed;
        private static string _textFromFile;
        private static bool _crashCheck = false, _firstTap = true;
        private static RenderStates _states;
        private static Text _text, _curText, _bestText, _recordText;
        private static Font _font;

        private abstract class GameObjects
        {
            public abstract void SetPos();
            public abstract void Drawing();
        }
        private class Player : GameObjects
        {
            private float _posX = 279, _posY = 360;
            private bool _leftMove = true;
            public override void SetPos()
            {
                if (!_crashCheck)
                {
                    _veterAnimation();
                    if (_firstTap)
                       _startAnimation();
                    if (Keyboard.IsKeyPressed(Keyboard.Key.Right) && _posX <= 558)
                    {
                        _moving(7f);
                        _firstTap = false;
                    }
                    if (Keyboard.IsKeyPressed(Keyboard.Key.Left) && _posX >= 0) 
                    {
                        _moving(-7f);
                        _firstTap = false;
                    }
                }
            }
            public override void Drawing()
            { 
                _bird.Size = new Vector2f(42, 29);
                _bird.Position = new Vector2f(_posX, _posY);
                _window.Draw(_bird, _states);
            }

            private void _moving(float dx)
            {
                _posX += dx;
            }
            private void _veterAnimation() 
            {
                if (_posX <= 558 && _posX >= 0)
                {
                    _posX += _speed;
                }
            }
            private void _startAnimation()
            {
                if (_leftMove)
                {
                    _posX -= 1f;
                    if (_posX == 249)
                       _leftMove = false;
                }
                if (!_leftMove)
                {
                    _posX += 1f;
                    if (_posX == 309)
                       _leftMove = true;
                }
            }
        } 
        private class FirstBlockLeft : GameObjects
        {
            private int _x, _y;
            public FirstBlockLeft(int _x, int _y) 
            {
                this._x = _x;
                this._y = _y;
            }
            public override void SetPos()
            {
                if (!_firstTap && !_crashCheck)
                    _y += 2;
            }
            public override void Drawing()
            {
                _snitch = new RectangleShape();
                _snitch.FillColor = new Color(71, 168, 74);
                _checkPos();
                _snitch.Size = new Vector2f(250 + _q, 100);
                _snitch.Texture = new Texture("Sprites/ground.png");
                _snitch.Position = new Vector2f(_x, _y); 
                _checkCollision();
                _window.Draw(_snitch);
            }
            private void _checkPos()
            {
                if (_y == 780)
                {
                    _y = -100;
                }
            }
            private static void _checkCollision()
            {
                if (_bird.GetGlobalBounds().Intersects(_snitch.GetGlobalBounds())) 
                    _crashCheck = true;
            }
        }
        private class FirstBlockRight : GameObjects
        {
            private int _x, _y;
            public FirstBlockRight(int _x, int _y) 
            {
                this._x = _x;
                this._y = _y;
            }
            public override void SetPos()
            {
                if (!_firstTap && !_crashCheck)
                    _y += 2;
            }
            public override void Drawing()
            {
                _snitch = new RectangleShape();
                _snitch.FillColor = new Color(71, 168, 74);
                _checkPos();
                _snitch.Size = new Vector2f(250 + Math.Abs(_q), 100);
                _snitch.Texture = new Texture("Sprites/ground.png");
                _snitch.Position = new Vector2f(_x + _q, _y); 
                _checkCollision();
                _count();
                _window.Draw(_snitch);
            }

            private void _checkPos()
            {
                if (_y == 780)
                {
                    _y = -100;
                    _q = _rnd.Next(-200, 201);
                }
            }
            private static void _checkCollision()
            {
                if (_bird.GetGlobalBounds().Intersects(_snitch.GetGlobalBounds())) 
                    _crashCheck = true;
            }
            private void _count()
            {
                if (_y == _bird.Position.Y + 20)
                {
                    _progressCount += 1;
                    _speed = _rnd.Next(-6, 7);
                }
            }
        }
        private class SecondBlockLeft : GameObjects
        {
            private int _x, _y;
            public SecondBlockLeft(int _x, int _y) 
            {
                this._x = _x;
                this._y = _y;
            }
            public override void SetPos()
            {
                if (!_firstTap && !_crashCheck)
                    _y += 2;
            }
            public override void Drawing()
            {
                _snitch = new RectangleShape();
                _snitch.FillColor = new Color(71, 168, 74);
                _checkPos();
                _snitch.Size = new Vector2f(250 + _q1, 100);
                _snitch.Texture = new Texture("Sprites/ground.png");
                _snitch.Position = new Vector2f(_x, _y); 
                _checkCollision();
                _window.Draw(_snitch);
            }
            private void _checkPos()
            {
                if (_y == 780)
                {
                    _y = -100;
                }
            }
            private static void _checkCollision()
            {
                if (_bird.GetGlobalBounds().Intersects(_snitch.GetGlobalBounds())) 
                    _crashCheck = true;
            }
        }
        private class SecondBlockRight : GameObjects
        {
            private int _x, _y;
            public SecondBlockRight(int _x, int _y) 
            {
                this._x = _x;
                this._y = _y;
            }
            public override void SetPos()
            {
                if (!_firstTap && !_crashCheck)
                    _y += 2;
            }
            public override void Drawing()
            {
                _snitch = new RectangleShape();
                _snitch.FillColor = new Color(71, 168, 74);
                _checkPos();
                _snitch.Size = new Vector2f(250 + Math.Abs(_q1), 100);
                _snitch.Texture = new Texture("Sprites/ground.png");
                _snitch.Position = new Vector2f(_x + _q1, _y); 
                _checkCollision();
                _count();
                _window.Draw(_snitch);
            }

            private void _checkPos()
            {
                if (_y == 780)
                {
                    _y = -100;
                    _q1 = _rnd.Next(-200, 201);
                }
            }
            private static void _checkCollision()
            {
                if (_bird.GetGlobalBounds().Intersects(_snitch.GetGlobalBounds())) 
                    _crashCheck = true;
            }
            private void _count()
            {
                if (_y == _bird.Position.Y + 20)
                {
                    _progressCount += 1;
                    _speed = _rnd.Next(-6, 7);
                }
            }
        }
        private class Bullet : GameObjects
        {
            static Random rnd = new Random();
            private float _x = rnd.Next(20, 570), _y = -40;
            public override void SetPos()
            {
                if (!_firstTap && !_crashCheck)
                   _y += 5f;
            }
            public override void Drawing()
            {
                _snitch = new RectangleShape();
                _snitch.Size = new Vector2f(20, 40);
                _snitch.Texture = new Texture("Sprites/bullet.png");
                _checkPos();
                _snitch.Position = new Vector2f(_x, _y); 
                _checkCollision();
                _window.Draw(_snitch, _states);
            }
            private void _checkPos()
            {
                if (_y >= 740)
                {
                   _y = -40;
                   //_x = rnd.Next(20, 570);
                   _x = _bird.Position.X;
                }
            }
            private void _checkCollision()
            {
                if (_bird.GetGlobalBounds().Intersects(_snitch.GetGlobalBounds())) 
                    _crashCheck = true;
            }
        }
        
        private static void _recordPainting()
        {
            _bestRecord();
            _recordText.DisplayedString = "Your best: " +_textFromFile;
            _window.Draw(_recordText);
        }
        private static void _bestRecord()
        {
            string path = @"C:\Users\wwwro\Desktop\Projects\Flappik";
            using (FileStream fstream1 = new FileStream($"{path}/record", FileMode.OpenOrCreate))
            {
                byte[] array = new byte[fstream1.Length];
                fstream1.Read(array, 0, array.Length);
                _textFromFile = System.Text.Encoding.Default.GetString(array);
                if (_textFromFile == "")
                {
                    array = System.Text.Encoding.Default.GetBytes("0");
                    fstream1.Write(array, 0, array.Length);
                }
                _textFromFile = System.Text.Encoding.Default.GetString(array);
            }
            if (float.Parse(_textFromFile) < _progressCount)
            {
                using (FileStream fstream = new FileStream($"{path}/record", FileMode.Create))
                {
                    byte[] array = System.Text.Encoding.Default.GetBytes(Convert.ToString(_progressCount));
                    fstream.Write(array, 0, array.Length);
                }
            }
        }
        private static void _fontSettings()
        {
            _font = new Font("Sprites/Text1.ttf");
            _text = new Text($"", _font, 50);
            _text.Color = Color.Black;
            _text.Position = new Vector2f(290, 180);     

            _curText = new Text("", _font, 40);
            _curText.Color = Color.Black;
            _curText.Position = new Vector2f(140, 300);    

            _bestText = new Text("", _font, 40);
            _bestText.Color = Color.Black;
            _bestText.Position = new Vector2f(140, 350);   

            _recordText = new Text($"", _font, 25);
            _recordText.Color = Color.Black;
            _recordText.Position = new Vector2f(10, 10);
        }
        private static void _pngSettings()
        {
            var mode = new BlendMode();
            mode.ColorSrcFactor = BlendMode.Factor.SrcAlpha;
            mode.ColorDstFactor = BlendMode.Factor.OneMinusSrcAlpha;
            mode.ColorEquation = BlendMode.Equation.Add;
            mode.AlphaSrcFactor = BlendMode.Factor.SrcAlpha;
            mode.AlphaDstFactor = BlendMode.Factor.OneMinusSrcAlpha;
            mode.AlphaEquation = BlendMode.Equation.Add;
            _states = RenderStates.Default;
            _states.BlendMode = mode;
        }
        private static void _windowSet()
        {
            _window = new RenderWindow(new VideoMode(600, 720), "Flappik");
            _window.SetVerticalSyncEnabled(true);
            _texture.Position = new Vector2f(0, 0);
            _texture.Size = new Vector2f(600, 720);
            _texture.Texture = new Texture("Sprites/fone.png");
        }
        private static void _addingGameElements()
        {
            AllBlocks.Clear();
            AllBlocks.Add(new FirstBlockLeft(0, -100));
            AllBlocks.Add(new FirstBlockRight(400, -100));
            AllBlocks.Add(new SecondBlockLeft(0, -500));
            AllBlocks.Add(new SecondBlockRight(400, -500));
            AllBlocks.Add(new Bullet());
            AllBlocks.Add(new Player());
        }
        private static void _initialize()
        {
            //Console.WriteLine(Directory.GetCurrentDirectory());
            _windowSet();
            _pngSettings();
            _fontSettings();
            _addingGameElements();
            _bird.Texture = new Texture("Sprites/bird.png");
        }
        private static void _startMenu() 
        {
            Text _entryText;

            _entryText = new Text($"Flappik", _font, 60);
            _entryText.Color = Color.Black;
            _entryText.Position = new Vector2f(220, 240);

            _window.Draw(_entryText);
        }
        private static void _deathWindow()
        {
            Text _deathText;
            _deathText = new Text("You die! Press Enter to restart...", _font, 25);
            _deathText.Color = Color.Black;
            _deathText.Position = new Vector2f(140, 245); 
            RectangleShape backG = new RectangleShape();
            RectangleShape mainW = new RectangleShape();
            RectangleShape redW = new RectangleShape();
            backG.Position = new Vector2f(100, 220);
            backG.Size = new Vector2f(400, 280);
            backG.FillColor = Color.Black;
            mainW.Position = new Vector2f(110, 230);
            mainW.Size = new Vector2f(385, 265);
            mainW.FillColor = new Color(209, 229, 247);
            redW.Position = new Vector2f(105, 225);
            redW.Size = new Vector2f(395, 275);
            redW.FillColor = Color.Red;
            _curText.DisplayedString = $"This game:           {_progressCount}";
            _bestText.DisplayedString = "Best game:           " + _textFromFile;
            _window.Draw(backG);
            _window.Draw(redW);
            _window.Draw(mainW);
            _window.Draw(_deathText);
            _window.Draw(_curText);
            _window.Draw(_bestText);
        }
        private static void _deatheScene()
        {
            
            _deathWindow();
            if (Keyboard.IsKeyPressed(Keyboard.Key.Enter))
                {
                    _addingGameElements();
                    _progressCount = 0;
                    _speed = 0;
                    _crashCheck = false;
                }
        }
        private static void _gameProcess()
        {
            while (_window.IsOpen && !Keyboard.IsKeyPressed(Keyboard.Key.Escape))
            {
                _window.DispatchEvents();
                _window.Clear(Color.Black);
                _window.Draw(_texture); 
                foreach (var curB in AllBlocks) 
                { 
                    curB.SetPos(); 
                    curB.Drawing(); 
                }
                if (_firstTap)
                {
                    _startMenu();
                }
                else 
                {
                    if (!_crashCheck)
                    {
                        _text.DisplayedString = $"{_progressCount}";
                        _window.Draw(_text);
                    }
                }
                if (!_crashCheck)
                    _recordPainting();
                if (_crashCheck)
                    _deatheScene();
                _window.Display();
            }
        }
        public static void Renderer()
        {
            _initialize();
            _gameProcess();
        }
    }
}