if flock -n -x 8; then
  echo ""
  echo "Starting UDP logger..."
  echo ""
/root/main/venv/bin/python /root/main/udp/udp_rec.py
  echo ""
  echo "UDP Logger started  $DATE";
  echo "UDP Logger finished `date +%c`";
else
  echo "UDP Logger is still running at $DATE";
fi
